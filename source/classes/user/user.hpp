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
    std::string id = std::string();

    //
    // Value store a document or a view. The value need to be stored because the memory
    // between a view or document and a value its shared, if the view or document its
    // its saved, but the value its not, an error is issued.
    //
    // The value is updated if the personalized constructor or the search method is called
    //
    // https://stackoverflow.com/questions/56740730/unset-document-element-in-mongo-cxx/56741600?noredirect=1#comment100043541_56741600
    //
    bsoncxx::document::value value = bsoncxx::builder::stream::document{} << bsoncxx::builder::stream::finalize;

    //
    // View store an document visualization. The view is derived from a value, that is
    // derived from a document
    //
    // The view is updated if the personalized constructor or the search method is called
    //
    bsoncxx::document::view view;

    //
    // Collection store a database collection.
    //
    // The collection is only updated when the object is created
    //
    mongocxx::collection collection = Connection::collection(user_database_name, user_collection_name);

    //
    // Logged store the state of the user in the system, if the user is logged or not
    //
    // The logged status is only updated at the login function and in the personalized
    // constructor
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
    //   A OID, in string format
    //
    // This is a 'interface' to the implementation of Crud::search_one_by_id
    //
    const bool search_one_by_id(const std::string &);

    //
    // Search one document using any attribute that has a string value
    //
    // @param collection
    //   A database collection object
    //
    // @param attribute
    //   Attribute name, as a string
    //
    // @param attribute_value
    //   Attribute value, along with the attribute name to match
    //   a document
    //
    const bool search_one_by_string(const std::string &attribute, const std::string &attribute_value);

    //
    // Login
    //
    // @param email
    //   E-mail, to login in, along with a password
    //
    // @param password
    //   Password, to login in
    //
    const bool login(const std::string &email, const std::string &password);

    //
    // Get the login status
    //
    const bool login_status();

    //
    // Get a string attribute from a view
    //
    const std::string get_string_attribute(const std::string &attribute_name) const;
};

#endif // USER