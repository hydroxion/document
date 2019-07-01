#ifndef USER

#define USER

// Connection
#include "../connection/connection.hpp"

// CRUD
#include "../crud/crud.hpp"

// Standard I/O
#include <iostream>

// String
#include <string>

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
    std::string id = std::string();

    //
    // Value store a document value. The value need to be stored because the memory
    // between a view and a value is shared. If a view is derived from a value
    // and the reference to the value is removed, the view is not valid anymore
    //
    // https://stackoverflow.com/questions/56740730/unset-document-element-in-mongo-cxx/56741600?noredirect=1#comment100043541_56741600
    //
    bsoncxx::document::value value = bsoncxx::builder::stream::document{} << bsoncxx::builder::stream::finalize;

    //
    // View store an document visualization. The view is derived from a value
    //
    bsoncxx::document::view view;

    //
    // Collection store a database collection
    //
    mongocxx::collection collection = Connection::collection(user_database_name, user_collection_name);

    //
    // Logged store the login status
    //
    bool logged = false;

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
    // Destroys a user
    //
    ~User();

    //
    // Search one document by id
    //
    // @param id
    //   A OID
    //
    const bool search_one_by_id(const std::string &);

    //
    // Search one document by any attribute, that has a string value
    //
    // @param attribute
    //   Attribute name
    //
    // @param attribute_value
    //   Attribute value
    //
    const bool search_one_by_string(const std::string &, const std::string &);

    //
    // Get any string attribute, from a view
    //
    // @param attribute
    //   Attribute name
    //
    const std::string get_string_attribute(const std::string &);

    //
    // Login
    //
    // @param email
    //   E-mail, to login in, along with a password
    //
    // @param password
    //   Password, to login in
    //
    // https://www.geeksforgeeks.org/stdstringcompare-in-c/
    //
    const bool login(const std::string &, const std::string &);

    //
    // Login status
    //
    const bool login_status();

    //
    // Delete one document by id
    //
    // @param id
    //   A OID
    //
    const int delete_one_by_id();

    //
    // Update one document attribute, that has a string value, by id
    //
    // @param attribute
    //   Attribute name
    //
    // @param attribute_value
    //   Attribute value
    //
    const int update_one_by_id(const std::string &attribute, const std::string &attribute_value);
};

#endif // USER