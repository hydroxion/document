#include "crud.hpp"

Crud::Crud()
{
}

std::tuple<bool, std::string> Crud::insert_one(mongocxx::collection &collection, bsoncxx::document::view &view)
{
    try
    {
        bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(view);

        if (!result)
        {
            std::cout << "Unacknowledged write. No id available." << std::endl;

            return std::make_tuple(EXIT_SUCCESS, "");
        }

        if (result->inserted_id().type() == bsoncxx::type::k_oid)
        {
            bsoncxx::oid oid = result->inserted_id().get_oid().value;

            std::cout << "Inserted id: " << oid.to_string() << std::endl;

            return std::make_tuple(EXIT_SUCCESS, oid.to_string());
        }
        else
        {
            std::cout << "Inserted id was not an OID type" << std::endl;
        }
    }
    catch (const mongocxx::exception &error)
    {
        std::cerr << "An exception occurred: " << error.what() << std::endl;

        return std::make_tuple(EXIT_FAILURE, "");
    }

    return std::make_tuple(EXIT_SUCCESS, "");
}