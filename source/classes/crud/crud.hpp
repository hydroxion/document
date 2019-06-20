#ifndef CRUD

#define CRUD

// Standard I/O
#include <iostream>

// Logic error exception
#include <mongocxx/exception/logic_error.hpp>

// BSON Functionalities
#include <bsoncxx/json.hpp>

// BSON Document streaming interface
#include <bsoncxx/builder/stream/document.hpp>

// Mongo CXX namespace (and BSON polyfills)
#include <mongocxx/stdx.hpp>

// Mongo client connection
#include <mongocxx/client.hpp>

// Tuple
#include <tuple>

// String
#include <string>

class Crud
{
protected:
    //
    // Default CRUD
    //
    Crud();

    //
    // Insert one document (view) in a Mongo database collection
    //
    // @param collection
    //   A valid Mongo database collection
    //
    // @param view
    //   A valid BSON document view
    //
    // The return is a tuple, containing at the index 0 the status of the transaction
    // and at the index 1 the document id
    //
    // Using an uninitialized collection throws a mongocxx::logic_error. A
    // mongocxx::logic_error is a mongocxx::exception / std::system_error
    //
    // http://mongocxx.org/mongocxx-v3/tutorial/#insert-documents
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
    std::tuple<bool, std::string> insert_one(mongocxx::collection &, bsoncxx::document::view &);

    //
    // Search one document by the attribute _id
    //
    // @param collection
    //   A valid Mongo database collection
    //
    // @param id
    //   A OID in string format
    //
    // The return is a bsoncxx::document::value that can be decomposed in
    // a bsoncxx::document::view, that can then be decomposed in a
    // bsoncxx::document::element
    //
    // Example:
    //
    // bsoncxx::document::value value = Crud::search_one_by_id(collection, "id");
    //
    // bsoncxx::document::view view = value.view();
    //
    // bsoncxx::document::element element = view["attribute"];
    //
    // std::string attribute = element.get_utf8().value.to_string();
    //
    // To print the entire document, convert the same using bsoncxx::to_json(document)
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
    //
    // http://mongocxx.org/api/mongocxx-3.4.0/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    bsoncxx::document::value search_one_by_id(mongocxx::collection &, const std::string &);
};

#endif // CRUD