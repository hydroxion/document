#ifndef USER

#define USER

// BSON Streaming interface
#include <bsoncxx/builder/stream/document.hpp>

// Mongo connection
#include "../connection/connection.hpp"

// String
#include <string>

// Standard I/O+
#include <iostream>

// Mongo CXX namespace (and BSON polyfills)
#include <mongocxx/stdx.hpp>

// Data types
#include <bsoncxx/types.hpp>

// Logic error exception
#include <mongocxx/exception/logic_error.hpp>

class User : protected Connection
{
private:
    std::string id = "";

    bsoncxx::document::view document_view;

    //
    // Insert a document view in a Mongo database collection
    //
    // @param user_database_name
    //   A database name representing a valid Mongo database
    //
    // @param user_collection_name
    //   A collection name representing a valid Mongo collection from
    //   a database
    //
    // If the database or collection you request does not exist, Mongo
    // creates it when you first store data
    //
    // Using an uninitialized collection throws a mongocxx::logic_error. A
    // mongocxx::logic_error is a mongocxx::exception / std::system_error
    //
    // https://github.com/mongodb/mongo-cxx-driver/blob/master/examples/mongocxx/exception.cpp
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1exception.html
    //
    // https://stackoverflow.com/questions/13667364/exit-failure-vs-exit1
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1database.html
    //
    // http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    // http://mongocxx.org/mongocxx-v3/tutorial/#insert-documents
    //
    // http://mongocxx.org/api/current/classmongocxx_1_1result_1_1insert__one.html
    //
    // https://github.com/mongodb/mongo-cxx-driver/blob/eccd8b0a525f72d85d6153085e299c291d02acec/src/bsoncxx/types/value.hpp
    //
    bool insert()
    {
        try
        {
            mongocxx::collection collection = Connection::collection(user_database_name, user_collection_name);

            bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(this->document_view);

            if (!result)
            {
                std::cout << "Unacknowledged write. No id available." << std::endl;

                return EXIT_SUCCESS;
            }

            if (result->inserted_id().type() == bsoncxx::type::k_oid)
            {
                bsoncxx::oid oid = result->inserted_id().get_oid().value;

                std::string id = oid.to_string();

                this->id = id;

                std::cout << "Inserted id: " << this->id << std::endl;
            }
            else
            {
                std::cout << "Inserted id was not an OID type" << std::endl;
            }
        }
        catch (const mongocxx::exception &error)
        {
            std::cerr << "An exception occurred: " << error.what() << std::endl;

            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

public:
    //
    // Default user
    //
    User() : Connection()
    {
    }

    //
    // Personalized user
    //
    // @param first_name
    //   A user first name representing part of a user name
    //
    // @param second_name
    //   A user second name representing part of a user name
    //
    // @param email
    //   A user e-mail used to login, along with a password
    //
    // @param password
    //   A user password used to login, along with a e-mail
    //
    // When an user object is created, a document is also created in the Mongo
    // database and the id of the document stored in the private id attribute,
    // as a string. If a error is issued, the document don't have an id or the
    // id is bad formated; the id is not stored in the private id attribute
    //
    // http://mongocxx.org/mongocxx-v3/tutorial/#create-a-document
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1builder_1_1stream_1_1document.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1value.html
    //
    // http://mongocxx.org/api/current/classbsoncxx_1_1document_1_1view.html
    //
    User(const std::string first_name, const std::string second_name, const std::string email, const std::string password) : Connection()
    {
        auto document = bsoncxx::builder::stream::document{};

        bsoncxx::document::value document_value = document
                                                  << "first_name" << bsoncxx::types::b_utf8{first_name}
                                                  << "second_name" << bsoncxx::types::b_utf8{second_name}
                                                  << "email" << bsoncxx::types::b_utf8{email}
                                                  << "password" << bsoncxx::types::b_utf8{password}
                                                  << bsoncxx::builder::stream::finalize;

        this->document_view = document_value.view();

        this->insert();
    }

    void search()
    {
        mongocxx::collection collection = Connection::collection(user_database_name, user_collection_name);

        bsoncxx::stdx::optional<bsoncxx::document::value> query_result =
            collection.find_one(bsoncxx::builder::stream::document{} << "_id"
                                                                    << bsoncxx::oid("5d08f65f2a554e7cfd1e9fe2")
                                                                     << bsoncxx::builder::stream::finalize);

        bsoncxx::document::value doc_value = *query_result;

        bsoncxx::document::view view = doc_value.view();

        bsoncxx::document::element element = view["first_name"];

        std::cout << element.get_utf8().value.to_string();;
        
        //    if(query_result) {
        //     std::cout << bsoncxx::to_json(*query_result) << "\n";
        //     }                                      
    }
};

#endif // USER