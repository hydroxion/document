#ifndef USER

#define USER

// Connection
#include "../connection/connection.hpp"

// Crud
#include "../crud/crud.hpp"

// Standard I/O
#include <iostream>

// Tuple
#include <tuple>

// BSON Exception
#include <bsoncxx/exception/exception.hpp>

class User : protected Connection, protected Crud
{
private:
    //
    // The id stores an user document identification. The default document identification
    // is created based on the OID pattern
    //
    std::string id = "";

    //
    // The view stores an user representation. The view is derived from a value, that is
    // derived from a document.
    //
    // By default the view is empty, but when an User object is created, i.g an user is registered,
    // and no errors are issued, the view receives the registered user document
    //
    bsoncxx::document::view view;

    //
    // The collection stores a Mongo database collection. If the database or collection
    // you request does not exist, Mongo creates it when you first store data
    //
    // The user database name and user collection name, come from the settings header,
    // which contains the shared variables
    //
    mongocxx::collection collection = Connection::collection(user_database_name, user_collection_name);

public:
    //
    // Default user
    //
    User();

    //
    // Personalized user
    //
    // @param first_name
    //   User first name, to display in the profile
    //
    // @param second_name
    //   User second name, to display in the profile
    //
    // @param email
    //   User e-mail, to login, along with a password
    //
    // @param password
    //   User password, to login, along with an e-mail
    //
    // When the personalized constructor its used, a document is created in a
    // database collection. The document id is stored in the private id attribute
    //
    // http://mongocxx.org/mongocxx-v3/tutorial/#create-a-document
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1builder_1_1stream_1_1document.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    User(const std::string, const std::string, const std::string, const std::string);

    void search_one_by_id()
    {
        try
        {
            bsoncxx::document::value value = Crud::search_one_by_id(this->collection, "5d0bb7042a554e44db53f142");

            bsoncxx::document::view view = value.view();

            bsoncxx::document::element element = view["first_name"];

            std::cout << element.get_utf8().value.to_string() << std::endl;
        }
        catch (const bsoncxx::v_noabi::exception &error)
        {
            std::cerr << "An exception occurred: "
                      << error.what()
                      << ". File \033[34m"
                      << __FILE__
                      << "\033[m at function \033[31m"
                      << __FUNCTION__
                      << "\033[m"
                      << std::endl;
        }
    }
};

#endif // USER