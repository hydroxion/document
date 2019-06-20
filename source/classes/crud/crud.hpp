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

// BSON Document streaming interface
#include <bsoncxx/builder/stream/document.hpp>

// Mongo CXX namespace (and BSON polyfills)
#include <mongocxx/stdx.hpp>

// Mongo client connection
#include <mongocxx/client.hpp>

class Crud
{
protected:
    //
    // Default CRUD
    //
    Crud();

    //
    // Insert one document view in a Mongo database collection
    //
    // @param collection
    //   A database collection object
    //
    // @param view
    //   A BSON document view
    //
    // Using an uninitialized collection throws a mongocxx::logic_error. A
    // mongocxx::logic_error is a mongocxx::exception / std::system_error
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
    const virtual std::tuple<bool, std::string> insert_one(mongocxx::collection &, bsoncxx::document::view &);

    //
    // Search one document by id
    //
    // @param collection
    //   A database collection object
    //
    // @param id
    //   A OID, in string format
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
    //
    // http://mongocxx.org/api/mongocxx-3.4.0/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    const  std::tuple<bool, bsoncxx::document::view> search_one_by_id(mongocxx::collection &, const std::string &);
};

#endif // CRUD