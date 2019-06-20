#include "user.hpp"

User::User() : Connection(), Crud()
{
}

User::User(const std::string first_name = "", const std::string second_name = "", const std::string email = "", const std::string password = "") : Connection(), Crud()
{
    auto document = bsoncxx::builder::stream::document{};

    bsoncxx::document::value value = document
                                     << "first_name" << bsoncxx::types::b_utf8{first_name}
                                     << "second_name" << bsoncxx::types::b_utf8{second_name}
                                     << "email" << bsoncxx::types::b_utf8{email}
                                     << "password" << bsoncxx::types::b_utf8{password}
                                     << bsoncxx::builder::stream::finalize;

    this->view = value.view();

    auto status = Crud::insert_one(this->collection, this->view);

    // Error
    if (std::get<0>(status))
    {
    }

    this->id = std::get<1>(status);
}