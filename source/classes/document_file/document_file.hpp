#ifndef DOCUMENT_FILE

#define DOCUMENT_FILE

// Connection
#include "../connection/connection.hpp"

// CRUD
#include "../crud/crud.hpp"

// Standard I/O
#include <iostream>

// String
#include <string>

// Settings
#include "../../settings/settings.hpp"

// File stream
#include <fstream>

class DocumentFile : protected Connection, protected Crud
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
    mongocxx::collection collection = Connection::collection(document_file_database_name, document_file_collection_name);

public:
    //
    // Default document file
    //
    DocumentFile();

    //
    // Personalized document file
    //
    // @param path
    //   Path to a binary file
    //
    DocumentFile(const std::string &);

    //
    // Destroys a document file
    //
    ~DocumentFile();

    std::ifstream read_file(const std::string &);

    uint32_t file_size(std::ifstream &, std::filebuf *filebuf);

    std::string file_name(std::string, char seperator = '/');

    std::string extension_name(std::string);

    int upload(const std::string &);

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
    const std::string get_document_oid(const std::string);

    //
    // Delete one document by id
    //
    // @param id
    //   A OID
    //
    const int delete_one_by_id();

    int download(const std::string &);
};

#endif // DOCUMENT_FILE