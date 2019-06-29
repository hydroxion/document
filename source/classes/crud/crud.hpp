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
};

#endif // CRUD