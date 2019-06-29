#include "crud.hpp"

Crud::Crud()
{
}

Crud::~Crud()
{
}

const std::tuple<bool, std::string> Crud::insert_one(mongocxx::collection &collection, const bsoncxx::document::view &view) const
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

const std::tuple<bool, bsoncxx::document::value> Crud::search_one_by_id(mongocxx::collection &collection, const std::string &id) const
{
    try
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
                      << " or the attribute don't exist in the collection documents"
                      << std::endl;

            return std::make_tuple(EXIT_FAILURE, (*result));
        }
        else
        {
            std::cout << "Search one by id: \033[32m"
                      << id
                      << "\033[m"
                      << std::endl;

            return std::make_tuple(EXIT_SUCCESS, (*result));
        }
    }
    catch (const bsoncxx::v_noabi::exception &error)
    {
        bsoncxx::stdx::optional<bsoncxx::document::value> result;

        std::cerr << "An exception occurred: "
                  << error.what()
                  << ". File \033[34m"
                  << __FILE__
                  << "\033[m at function \033[31m"
                  << __FUNCTION__
                  << "\033[m"
                  << std::endl;

        return std::make_tuple(EXIT_FAILURE, (*result));
    }
}

const std::tuple<bool, bsoncxx::document::value> Crud::search_one_by_string(mongocxx::collection &collection, const std::string &attribute, const std::string &attribute_value) const
{
    bsoncxx::stdx::optional<bsoncxx::document::value> result =
        collection.find_one(bsoncxx::builder::stream::document{} << bsoncxx::types::b_utf8{attribute}
                                                                 << bsoncxx::types::b_utf8{attribute_value}
                                                                 << bsoncxx::builder::stream::finalize);

    if (!result)
    {
        std::cerr << "The " << attribute << ": \033[33m"
                  << attribute_value
                  << "\033[m, don't match any document in "
                  << collection.name()
                  << " or the attribute don't exist in the collection documents"
                  << std::endl;

        return std::make_tuple(EXIT_FAILURE, (*result));
    }
    else
    {
        std::cout << "Search one by string (" << attribute << "): \033[32m"
                  << attribute_value
                  << "\033[m"
                  << std::endl;

        return std::make_tuple(EXIT_SUCCESS, (*result));
    }
}

const std::string Crud::get_string_attribute(const std::string &attribute_name, const bsoncxx::document::view &view) const
{
    if (view.empty())
    {
        std::cout << "Empty view. No search was made"
                  << std::endl;

        return std::string();
    }

    //
    // The exception don't share scope, its required to place the entire
    // code in the try block or place the instances outside the block
    //
    try
    {
        bsoncxx::document::element element = view[attribute_name];

        if (element.type() != bsoncxx::type::k_utf8)
        {
            std::cerr << "Invalid element type"
                      << ". File \033[34m"
                      << __FILE__
                      << "\033[m at function \033[31m"
                      << __FUNCTION__
                      << "\033[m"
                      << std::endl;

            return std::string();
        }

        return element.get_utf8().value.to_string();
    }
    catch (const bsoncxx::v_noabi::exception &error)
    {
        std::cerr << "Attribute not found in view ("
                  << error.what()
                  << "). File \033[34m"
                  << __FILE__
                  << "\033[m at function \033[31m"
                  << __FUNCTION__
                  << "\033[m"
                  << std::endl;

        return std::string();
    }
}