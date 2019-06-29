#ifndef CRUD

#define CRUD

// Standard I/O
#include <iostream>

// Logic error exception
#include <mongocxx/exception/logic_error.hpp>

// Tuple
#include <tuple>

// String
#include <string>

// BSON Functionalities
#include <bsoncxx/json.hpp>

// BSON Exception
#include <bsoncxx/exception/exception.hpp>

// BSON Document interface
#include <bsoncxx/builder/stream/document.hpp>

// Mongo CXX namespace (and BSON polyfills)
#include <mongocxx/stdx.hpp>

// Mongo client
#include <mongocxx/client.hpp>

// Bulk exception
#include <mongocxx/exception/bulk_write_exception.hpp>

class Crud
{
protected:
    //
    // Default CRUD
    //
    Crud();

    //
    // Destroys a crud
    //
    ~Crud();

    //
    // Insert one document in a collection
    //
    // @param collection
    //   A database collection
    //
    // @param view
    //   A BSON document view
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1exception.html
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
    //
    // http://mongocxx.org/api/mongocxx-3.4.0/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    // http://mongocxx.org/api/current/classmongocxx_1_1result_1_1insert__one.html
    //
    const std::tuple<bool, std::string> insert_one(mongocxx::collection &, const bsoncxx::document::view &) const;

    //
    // Search one document by id
    //
    // @param collection
    //   A database collection
    //
    // @param id
    //   A OID
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
    //
    // http://mongocxx.org/api/mongocxx-3.4.0/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    const std::tuple<bool, bsoncxx::document::value> search_one_by_id(mongocxx::collection &, const std::string &) const;

    //
    // Search one document by any attribute, that has a string value
    //
    // @param collection
    //   A database collection
    //
    // @param attribute
    //   Attribute name
    //
    // @param attribute_value
    //   Attribute value
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
    //
    // http://mongocxx.org/api/mongocxx-3.4.0/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    const std::tuple<bool, bsoncxx::document::value> search_one_by_string(mongocxx::collection &, const std::string &, const std::string &) const;

    //
    // Get any attribute, from a view
    //
    // @param attribute
    //   Attribute name
    //
    // @param view
    //   A BSON document view
    //
    // http://mongocxx.org/api/mongocxx-3.4.0/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    const std::string get_string_attribute(const std::string &, const bsoncxx::document::view &) const;

    //
    // Delete one document by id
    //
    // @param collection
    //   A database collection
    //
    // @param id
    //   A OID
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
    //
    // http://mongocxx.org/api/current/classmongocxx_1_1collection.html#a7c6a65c7da3c14692c226ca86d108c39
    //
    // http://mongocxx.org/api/current/classmongocxx_1_1result_1_1delete__result.html
    //
    const int delete_one_by_id(mongocxx::collection &, const std::string &);

    //
    // Update one document attribute, that has a string value, by id
    //
    // @param collection
    //   A database collection
    //
    // @param id
    //   A OID
    //
    // @param attribute
    //   Attribute name
    //
    // @param attribute_value
    //   Attribute value
    //
    // If some attribute that don't exist in the document, that is being update,
    // is received, the attribute its created if the document is found by the id
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
    //
    // http://mongocxx.org/api/current/classmongocxx_1_1collection.html#aece5216e5ae6fc3316c9da604f3b28f9
    //
    // http://mongocxx.org/api/current/classmongocxx_1_1result_1_1update.html
    //
    const int update_one_by_id(mongocxx::collection &, const std::string &, const std::string &, const std::string &) const;
};

#endif // CRUD