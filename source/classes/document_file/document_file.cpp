#include "document_file.hpp"

DocumentFile::DocumentFile() : Connection(), Crud()
{
}

DocumentFile::DocumentFile(const std::string &path) : Connection(), Crud()
{
    this->upload(path);
}

DocumentFile::~DocumentFile()
{
}

std::ifstream DocumentFile::read_file(const std::string &path)
{
    std::ifstream file(path, std::ifstream::in | std::ifstream::binary);

    return file;
}

uint32_t DocumentFile::file_size(std::ifstream &file, std::filebuf *filebuf)
{
    uint32_t size = filebuf->pubseekoff(0, file.end, file.in);

    filebuf->pubseekpos(0, file.in);

    return size;
}

std::string DocumentFile::file_name(std::string path, char seperator)
{
    if (path.find_last_of(seperator) != std::string::npos)
    {
        return path.substr(path.rfind(seperator) + 1);
    }

    return std::string();
}

std::string DocumentFile::extension_name(std::string path)
{
    return path.substr(path.find_last_of(".") + 1);
}

int DocumentFile::upload(const std::string &path)
{
    std::string extension = this->extension_name(path);

    if (!(document_file_valid_format.find(extension) != std::string::npos))
    {
        std::string _extension = extension.size() ? extension : "empty string";

        std::cout << "Invalid file format: "
                  << _extension
                  << std::endl;

        return EXIT_FAILURE;
    }

    std::ifstream file = this->read_file(path);

    if (!file.is_open())
    {
        std::cout << "Was not possible to open the file (input stream), try another path" << std::endl;

        file.close();

        return EXIT_FAILURE;
    }

    std::filebuf *filebuf = file.rdbuf();

    uint32_t size = this->file_size(file, filebuf);

    std::cout << "File size (upload): " << size << std::endl;

    char *buffer = new char[size];

    if (!buffer)
    {
        std::cout << "Buffer not allocated" << std::endl;

        file.close();

        return EXIT_FAILURE;
    }

    filebuf->sgetn(buffer, size);

    bsoncxx::document::value value = bsoncxx::builder::stream::document{}
                                     << "name" << bsoncxx::types::b_utf8{this->file_name(path)}
                                     << "size" << bsoncxx::types::b_int64{size}
                                     << "extension" << bsoncxx::types::b_utf8{extension}
                                     << "archive" << bsoncxx::types::b_binary{bsoncxx::binary_sub_type::k_binary, size, (uint8_t *)buffer}
                                     << bsoncxx::builder::stream::finalize;

    delete[] buffer;

    file.close();

    auto status = Crud::insert_one(this->collection, value.view());

    if (std::get<0>(status))
    {
        // Error
        std::cerr << "Internal error when creating an object"
                  << ". File \033[34m"
                  << __FILE__
                  << "\033[m at function \033[31m"
                  << __FUNCTION__
                  << "\033[m"
                  << std::endl;

        return EXIT_FAILURE;
    }
    else
    {
        this->id = std::get<1>(status);

        return EXIT_SUCCESS;
    }
}

const bool DocumentFile::search_one_by_id(const std::string &id)
{
    auto status = Crud::search_one_by_id(this->collection, id);

    if (std::get<0>(status))
    {
        // Error
        return EXIT_FAILURE;
    }
    else
    {
        this->value = std::get<1>(status);

        this->view = this->value.view();

        this->id = DocumentFile::get_document_oid("_id");

        return EXIT_SUCCESS;
    }
}

const bool DocumentFile::search_one_by_string(const std::string &attribute, const std::string &attribute_value)
{
    auto status = Crud::search_one_by_string(this->collection, attribute, attribute_value);

    if (std::get<0>(status))
    {
        // Error
        return EXIT_FAILURE;
    }
    else
    {
        this->value = std::get<1>(status);

        this->view = this->value.view();

        this->id = DocumentFile::get_document_oid("_id");

        return EXIT_SUCCESS;
    }
}

const std::string DocumentFile::get_string_attribute(const std::string &attribute_name)
{
    return Crud::get_string_attribute(attribute_name, this->view);
}

const std::string DocumentFile::get_document_oid(const std::string attribute)
{
    return Crud::get_document_oid(this->view, attribute);
}

const int DocumentFile::delete_one_by_id()
{
    if (this->id.empty())
    {
        std::cout << "\033[33mId\033[m not found in the object"
                  << std::endl;

        return EXIT_FAILURE;
    }
    else
    {
        unsigned exit_status = Crud::delete_one_by_id(this->collection, this->id);

        if (!exit_status)
        {
            this->id = std::string();

            this->value = bsoncxx::builder::stream::document{} << bsoncxx::builder::stream::finalize;

            this->view = bsoncxx::document::view{};
        }

        return exit_status;
    }
}

int DocumentFile::download(const std::string &path)
{
    std::ofstream file(path + this->get_string_attribute("name"));

    if (!file.is_open())
    {
        std::cout << "Was not possible to open the file (output stream), try another path" << std::endl;

        file.close();

        return EXIT_FAILURE;
    }

    std::cout << "File size (download): " << view["archive"].get_binary().size << std::endl;

    file.write((char *)view["archive"].get_binary().bytes, view["archive"].get_binary().size);

    file.close();

    return EXIT_SUCCESS;
}