#include "connection.hpp"

#ifndef CONNECTION_INSTANCE

#define CONNECTION_INSTANCE

//
// The mongocxx::instance initialize and shut down the driver
//
// Only one mongocxx::instance must exist for the entirety of
// the program
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