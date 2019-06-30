#include "document.hpp"

Document::Document() : Connection(), Crud()
{
}

Document::Document(const std::string &user_id, const std::string &title, const std::string &type, const std::string &idiom, std::vector<std::string> &category, std::vector<std::string> &keyword) : Connection(), Crud()
{
    mongocxx::collection _collection = Connection::collection(user_database_name, user_collection_name);

    auto status_id = Crud::search_one_by_id(_collection, user_id);

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