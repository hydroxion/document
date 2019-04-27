#include "connection.hpp"

#ifndef CONNECTION_INSTANCE

#define CONNECTION_INSTANCE

///
/// Only one instance must exist for the entirety of the program
///
/// Don't use static or nest the instance in a class, it can cause
/// segmentation fault
///
mongocxx::instance instance;

#endif // CONNECTION_INSTANCE

Connection::Connection()
{
}

Connection::Connection(const std::string &mongodb_uri)
{
	this->mongo_uri = mongo_uri;

	this->client = mongocxx::client{mongocxx::uri{mongodb_uri}};
}

Connection::~Connection()
{
}

const mongocxx::database Connection::get_database(const std::string &database_name) const
{
	return this->client[database_name];
}

const mongocxx::collection Connection::get_collection(const std::string &database_name, const std::string &collection_name) const
{
	return this->get_database(database_name)[collection_name];
}