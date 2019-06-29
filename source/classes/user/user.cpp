#include "user.hpp"

User::User() : Connection(), Crud()
{
}

User::User(const std::string &first_name = "", const std::string &second_name = "", const std::string &email = "", const std::string &password = "") : Connection(), Crud()
{
    auto status_email = Crud::search_one_by_string(this->collection, "email", email);

    if (!std::get<0>(status_email))
    {
        this->logged = false;

        std::cerr << "E-mail duplicated. The registration was not allowed."
                  << std::endl;

        return;
    }

    auto document = bsoncxx::builder::stream::document{};

    this->value = document
                  << "first_name" << bsoncxx::types::b_utf8{first_name}
                  << "second_name" << bsoncxx::types::b_utf8{second_name}
                  << "email" << bsoncxx::types::b_utf8{email}
                  << "password" << bsoncxx::types::b_utf8{password}
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

        this->logged = true;
    }
}

User::~User()
{
}

const bool User::search_one_by_id(const std::string &id)
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

        return EXIT_SUCCESS;
    }
}

const bool User::search_one_by_string(const std::string &attribute, const std::string &attribute_value)
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

const std::string User::get_string_attribute(const std::string &attribute_name)
{
    return Crud::get_string_attribute(attribute_name, this->view);
}

const bool User::login(const std::string &email, const std::string &password)
{
    auto status = Crud::search_one_by_string(this->collection, "email", email);

    if (std::get<0>(status))
    {
        // Error
        this->logged = false;

        return EXIT_FAILURE;
    }

    bsoncxx::document::value value = std::get<1>(status);

    if (Crud::get_string_attribute("password", value.view()).compare(password) == 0)
    {
        this->value = value;

        this->view = this->value.view();

        this->logged = true;

        std::cout << "Access granted"
                  << std::endl;

        return EXIT_SUCCESS;
    }
    else
    {
        this->logged = false;

        std::cout << "Access denied"
                  << std::endl;

        return EXIT_FAILURE;
    }
}

const bool User::login_status()
{
    return this->logged;
}
