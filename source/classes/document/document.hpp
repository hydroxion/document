#ifndef DOCUMENT

#define DOCUMENT

// Connection
#include "../connection/connection.hpp"

// CRUD
#include "../crud/crud.hpp"

// Standard I/O
#include <iostream>

// Settings
#include "../../settings/settings.hpp"

// Vector
#include <vector>

// Tuple
#include <tuple>

// Chrono
#include <chrono>

class Document : protected Connection, protected Crud
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
    mongocxx::collection collection = Connection::collection(document_database_name, document_collection_name);

public:
    //
    // Default document
    //
    Document();

    //
    // Personalized document
    //
    // @param user_id
    //   A OID, that indicates who the document bellongs to
    //
    // @param title
    //   Document title
    //
    // @param type
    //   Document type, that indicates if the document is it an Ebook, Book,
    //   Slide, etc
    //
    // @param idiom
    //   Document idiom, that indicates which is the document language
    //
    // @param category
    //   An array, that indicates which category (ies) the document bellongs
    //   to, e.g algorithm, network, deep learn, etc
    //
    // @param keyword
    //    An array, that indicates which keyword (s) the document has, i.e the
    //    words that describe the main content of the document
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1builder_1_1stream_1_1document.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    // http://www.cplusplus.com/reference/chrono/system_clock/
    //
    // https://stackoverflow.com/questions/6012663/get-unix-timestamp-with-c
    //
    // https://docs.mongodb.com/manual/reference/method/Date/
    //
    // https://stackoverflow.com/questions/409348/iteration-over-stdvector-unsigned-vs-signed-index-variable
    //
    // https://stackoverflow.com/questions/2236197/what-is-the-easiest-way-to-initialize-a-stdvector-with-hardcoded-elements
    //
    explicit Document(const std::string &, const std::string &, const std::string &, const std::string &, std::vector<std::string> &, std::vector<std::string> &);

    //
    // Destroys a document
    //
    ~Document();

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
    // Get any oid attribute
    //
    // @param attribute
    //   Attribute name
    //
    const std::string get_document_oid(const std::string attribute = "_id");

    //
    // Get any date attribute
    //
    // @param attribute
    //   Attribute name
    //
    const std::string get_document_iso_date(const std::string attribute = "created_at");

    //
    // Delete one document by id
    //
    // @param id
    //   A OID
    //
    const int delete_one_by_id();
};

#endif // DOCUMENT