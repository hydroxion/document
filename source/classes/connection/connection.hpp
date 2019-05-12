#ifndef CONNECTION

#define CONNECTION

#include <mongocxx/client.hpp>

#include <mongocxx/uri.hpp>

#include <mongocxx/instance.hpp>

class Connection
{
private:
	//
	// https://docs.mongodb.com/manual/reference/connection-string/
	//
	std::string *uri = new std::string("mongodb://127.0.0.1:27017");

	//
	// Note that client is not thread-safe, for each thread its necessary to
	// give its own client. Don't create two or more clients derived from the
	// same client in one thread, e.g, std::mutex.
	//
	// https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/thread-safety/
	//
	mongocxx::client client{mongocxx::uri{*this->uri}};

public:
	//
	// Default connection to Mongo
	//
	// http://mongocxx.org/api/mongocxx-3.3.0/classmongocxx_1_1client.html
	//
	Connection();

	//
	// Personalized connection to Mongo
	//
	// @param uri
	//   An URI representing the connection parameters
	//
	// Additional options can be specified via options parameter
	//
	// http://mongocxx.org/api/mongocxx-3.3.0/classmongocxx_1_1client.html
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
	//   A database name representing a valid Mongo database
	//
	// A database cannot be obtained from a temporary client object
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
	//   A collection name representing a valid Mongo collection from a database
	//
	// http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
	//
	// https://en.wikipedia.org/wiki/Virtual_method_table
	//
	virtual const mongocxx::collection collection(const std::string &, const std::string &) const;
};

#endif // CONNECTION