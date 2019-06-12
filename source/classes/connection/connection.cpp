#include "connection.hpp"

#ifndef CONNECTION_INSTANCE

#define CONNECTION_INSTANCE

//
// Only one instance must exist for the entirety of the program
//
// Don't use static, nest the instance in a class or place the
// instance in the HPP file; it can cause segmentation fault
//
mongocxx::instance instance;

#endif // CONNECTION_INSTANCE

Connection::Connection()
{
}

Connection::Connection(const std::string &uri)
{
	this->uri = new std::string(uri);

	this->client = mongocxx::client{mongocxx::uri{*this->uri}};
}

Connection::~Connection()
{
	delete this->uri;

	this->uri = nullptr;
}

const mongocxx::database Connection::database(const std::string &database_name) const
{
	return this->client[database_name];
}

const mongocxx::collection Connection::collection(const std::string &database_name, const std::string &collection_name) const
{
	return this->database(database_name)[collection_name];
}