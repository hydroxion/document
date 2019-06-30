#include "document.hpp"

Document::Document() : Connection(), Crud()
{
}

Document::Document(const std::string &user_id, const std::string &title, const std::string &type, const std::string &idiom, std::vector<std::string> &category, std::vector<std::string> &keyword) : Connection(), Crud()
{
    mongocxx::collection user_collection = Connection::collection(user_database_name, user_collection_name);

    auto status_id = Crud::search_one_by_id(user_collection, user_id);

    if (std::get<0>(status_id))
    {
        return;
    }

    auto _category = bsoncxx::builder::basic::array{};

    for (const auto &value : category)
        _category.append(value);

    auto _keyword = bsoncxx::builder::basic::array{};

    for (const auto &value : keyword)
        _keyword.append(value);

    auto document = bsoncxx::builder::stream::document{};

    this->value = document
                  << "user_id" << bsoncxx::types::b_utf8{user_id}
                  << "title" << bsoncxx::types::b_utf8{title}
                  << "type" << bsoncxx::types::b_utf8{type}
                  << "idiom" << bsoncxx::types::b_utf8{idiom}
                  << "category" << _category
                  << "keyword" << _keyword
                  << "created_at" << bsoncxx::types::b_date(std::chrono::system_clock::now())
                  << bsoncxx::builder::stream::finalize;

    this->view = value.view();

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
    }
    else
    {
        this->id = std::get<1>(status);
    }
}

Document::~Document()
{
}

const bool Document::search_one_by_id(const std::string &id)
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

        this->id = Document::get_document_oid("_id");

        return EXIT_SUCCESS;
    }
}

const bool Document::search_one_by_string(const std::string &attribute, const std::string &attribute_value)
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

        return EXIT_SUCCESS;
    }
}

const std::string Document::get_string_attribute(const std::string &attribute_name)
{
    return Crud::get_string_attribute(attribute_name, this->view);
}

const std::string Document::get_document_oid(const std::string attribute)
{
    return Crud::get_document_oid(this->view, attribute);
}

const std::string Document::get_document_iso_date(const std::string attribute)
{
    return Crud::get_document_iso_date(this->view, attribute);
}

const int Document::delete_one_by_id()
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