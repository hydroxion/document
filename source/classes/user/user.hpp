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

// Settings
#include "../../settings/settings.hpp"

class User : protected Connection, protected Crud
{
private:
    //
    // ID store an document identification
    //
    std::string id = "";

    //
    // View store an document visualization. The view is derived from a value, that is
    // derived from a document
    //
    bsoncxx::document::view view;

    //
    // Collection store a database collection
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
    //   First name
    //
    // @param second_name
    //   second name
    //
    // @param email
    //   E-mail, to login in, along with a password
    //
    // @param password
    //   Password, to login in
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1builder_1_1stream_1_1document.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    explicit User(const std::string &, const std::string &, const std::string &, const std::string &);

    //
    // Search one document by id
    //
    // @param id
    //   A OID, in string format
    //
    // This is a 'interface' to the implementation of Crud::search_one_by_id
    //
    const bool search_one_by_id(const std::string &);
};

#endif // USER