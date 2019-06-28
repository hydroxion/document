#include "connection.hpp"

#ifndef CONNECTION_INSTANCE

#define CONNECTION_INSTANCE

//
// The mongocxx::instance initialize and shut down Mongo the drive. Only
//one instance must exist for the entirety of the program
//
// Don't create a static mongocxx::instance, nest the mongocxx::instance
// in a class or place the mongocxx::instance in the HPP file; it can
// cause segmentation fault
//
mongocxx::instance instance;

#endif // CONNECTION_INSTANCE

Connection::Connection()
{
}

Connection::Connection(const std::string &uri)
{
	this->uri = uri;

	this->client = mongocxx::client{mongocxx::uri{this->uri}};
}

Connection::~Connection()
{
}

const mongocxx::database Connection::database(const std::string &database_name) const
{
	return this->client[database_name];
}

const mongocxx::collection Connection::collection(const std::string &database_name, const std::string &collection_name) const
{
	return this->database(database_name)[collection_name];
}

const int Connection::ping() const
{
	try
	{
		bsoncxx::document::value value = bsoncxx::builder::stream::document{} << "ismaster"
																			  << bsoncxx::types::b_int32{1}
																			  << bsoncxx::builder::stream::finalize;

		bsoncxx::document::value result = this->client["admin"].run_command(value.view());

		bsoncxx::document::element element = result.view()["ok"];

		return (int)element.get_double().value;
	}
	catch (const mongocxx::operation_exception &error)
	{
		std::cerr << "An exception occurred: "
				  << error.what()
				  << ". File \033[34m"
				  << __FILE__
				  << "\033[m at function \033[31m"
				  << __FUNCTION__
				  << "\033[m"
				  << std::endl;

		return 0;
	}
}