#include "crud.hpp"

Crud::Crud()
{
}

const std::tuple<bool, std::string> Crud::insert_one(mongocxx::collection &collection, bsoncxx::document::view &view) const
{
    try
    {
        bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(view);

        if (!result)
        {
            std::cout << "Unacknowledged write. No id available"
                      << std::endl;

            return std::make_tuple(EXIT_SUCCESS, "");
        }

        if (result->inserted_id().type() == bsoncxx::type::k_oid)
        {
            bsoncxx::oid oid = result->inserted_id().get_oid().value;

            std::cout << "Inserted document id: \033[32m"
                      << oid.to_string()
                      << "\033[m"
                      << std::endl;

            return std::make_tuple(EXIT_SUCCESS, oid.to_string());
        }
        else
        {
            std::cout << "Inserted id was not an OID type"
                      << std::endl;
        }
    }
    catch (const mongocxx::exception &error)
    {
        std::cerr << "An exception occurred: "
                  << error.what()
                  << ". File \033[34m"
                  << __FILE__
                  << "\033[m at function \033[31m"
                  << __FUNCTION__
                  << "\033[m"
                  << std::endl;

        return std::make_tuple(EXIT_FAILURE, "");
    }

    return std::make_tuple(EXIT_SUCCESS, "");
}

Crud::~Crud()
{
}

const std::tuple<bool, bsoncxx::document::value> Crud::search_one_by_id(mongocxx::collection &collection, const std::string &id) const
{
    bsoncxx::stdx::optional<bsoncxx::document::value> result =
        collection.find_one(bsoncxx::builder::stream::document{} << "_id"
                                                                 << bsoncxx::oid(bsoncxx::types::b_utf8{id})
                                                                 << bsoncxx::builder::stream::finalize);

    if (!result)
    {
        std::cerr << "The id: \033[33m"
                  << id
                  << "\033[m, don't match any document in "
                  << collection.name()
                  << std::endl;

        return std::make_tuple(EXIT_FAILURE, (*result));
    }
    else
    {
        std::cout << "Search document id: \033[32m"
                  << id
                  << "\033[m"
                  << std::endl;

        return std::make_tuple(EXIT_SUCCESS, (*result));
    }
}