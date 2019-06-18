#ifndef CONNECTION

#define CONNECTION

// Mongo client connection (http://mongocxx.org/api/mongocxx-3.4.0/classmongocxx_1_1client.html)
#include <mongocxx/client.hpp>

// Mongo connection URI (http://mongocxx.org/api/mongocxx-3.4.0/classmongocxx_1_1uri.html)
#include <mongocxx/uri.hpp>

// Mongo driver instance (http://mongocxx.org/api/mongocxx-3.4.0/classmongocxx_1_1instance.html)
#include <mongocxx/instance.hpp>

// Settings
#include "../../settings/settings.hpp"

class Connection
{
private:
	//	
	// Mongo URI
	//
	// https://docs.mongodb.com/manual/reference/connection-string/
	//
	// https://stackoverflow.com/questions/7382602/what-is-the-difference-between-127-0-0-1-and-localhost
	//
	std::string uri{connection_prefix + connection_host + connection_port};

	//
	// Note that client is not thread-safe, for each thread its necessary to
	// give its own client. Don't create two or more clients derived from the
	// same client in one thread, e.g std::mutex.
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
	//   An URI representing the connection parameters
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
	//   A database name representing a valid Mongo database, if the
    //   database doesn't exist, this will be created
	//
	// A database cannot be obtained from a temporary client object
	//
	// If the database you request does not exist, Mongo creates it
	// when you first store data
	//
	// http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1database.html
	//
	// https://stackoverflow.com/questions/10897799/temporary-objects-when-are-they-created-how-do-you-recognise-them-in-code
	//
	// https://en.wikipedia.org/wiki/Virtual_method_table
	//
	virtual const mongocxx::database database(const std::string &) const;

	//
	// Get a collection from a database
	//
	// @param database_name
	//   A database name representing a valid Mongo database
	//
	// @param collection_name
	//   A collection name representing a valid Mongo collection from
	//   a database
	//
	// If the database or collection you request does not exist, Mongo
	// creates it when you first store data
	//
	// http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
	//
	// https://en.wikipedia.org/wiki/Virtual_method_table
	//
	virtual const mongocxx::collection collection(const std::string &, const std::string &) const;
};

#endif // CONNECTION