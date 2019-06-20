#ifndef CONNECTION

#define CONNECTION

// Mongo client connection
#include <mongocxx/client.hpp>

// Mongo connection URI
#include <mongocxx/uri.hpp>

// Mongo driver instance
#include <mongocxx/instance.hpp>

// Settings
#include "../../settings/settings.hpp"

// String
#include <string>

class Connection
{
private:
	//
	// URI store the connection parameters
	//
	// https://docs.mongodb.com/manual/reference/connection-string/
	//
	std::string uri{connection_prefix + connection_host + connection_port};

	//
	// Client store the connection to Mongo
	//
	// Note that client is not thread-safe, for each thread its necessary to
	// give its own client
	//
	// https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/thread-safety/
	//
	mongocxx::client client{mongocxx::uri{this->uri}};

protected:
	//
	// Default connection to Mongo
	//
	// http://mongocxx.org/api/mongocxx-3.4.0/classmongocxx_1_1client.html
	//
	Connection();

	//
	// Personalized connection to Mongo
	//
	// @param uri
	//   An URI store the connection parameters
	//
	// Additional options can be specified via 'options' parameter
	//
	// http://mongocxx.org/api/mongocxx-3.4.0/classmongocxx_1_1client.html
	//
	explicit Connection(const std::string &);

	//
	// Destroys a connection
	//
	~Connection();

	//
	// Get a database
	//
	// @param database_name
	//   A database name
	//
	// If the database you request doesn't exist, Mongo creates it
	// when you first store data
	//
	// A database can't be obtained from a temporary client object
	//
	// http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1database.html
	//
	// https://stackoverflow.com/questions/10897799/temporary-objects-when-are-they-created-how-do-you-recognise-them-in-code
	//
	const mongocxx::database database(const std::string &) const;

	//
	// Get a database collection
	//
	// @param database_name
	//   A database name
	//
	// @param collection_name
	//   A database collection name
	//
	// If the database you request doesn't exist, Mongo creates it
	// when you first store data
	//
	// http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
	//
	const mongocxx::collection collection(const std::string &, const std::string &) const;
};

#endif // CONNECTION