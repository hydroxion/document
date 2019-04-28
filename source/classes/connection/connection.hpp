#ifndef CONNECTION

#define CONNECTION

/// Mongo client
#include <mongocxx/client.hpp>

/// Mongo URI
#include <mongocxx/uri.hpp>

/// Mongo instance
#include <mongocxx/instance.hpp>

class Connection
{
private:
	///
	/// https://docs.mongodb.com/manual/reference/connection-string/
	///
	std::string mongo_uri{"mongodb://127.0.0.1:27017"};

	///
	/// Note that client is not thread-safe, for each thread its necessary to
	/// give its own mongocxx::client. Don't create two or more clients derived
	/// from the same mongocxx::client in one (e.g, std::mutex) thread.
	///
	/// https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/thread-safety/
	///
	mongocxx::client client{mongocxx::uri{this->mongo_uri}};

protected:
	///
	/// Constructs a default connection to Mongo
	///
	/// http://mongocxx.org/api/mongocxx-3.3.0/classmongocxx_1_1client.html
	///
	Connection();

	///
	/// Constructs a personalized connection to Mongo
	///
	/// @param mongodb_uri
	///   A Mongo URI representing the connection parameters
	///
	/// Additional options can be specified via options parameter
	///
	/// http://mongocxx.org/api/mongocxx-3.3.0/classmongocxx_1_1client.html
	///
	explicit Connection(const std::string &mongodb_uri);

	///
	/// Destroys a connection
	///
	~Connection();

	///
	/// Get a database
	///
	/// @param database_name
	///   A database name representing a valid Mongo database
	///
	/// A database cannot be obtained from a temporary client object
	///
	/// http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1database.html
	///
	/// https://stackoverflow.com/questions/10897799/temporary-objects-when-are-they-created-how-do-you-recognise-them-in-code
	///
	const mongocxx::database get_database(const std::string &database_name) const;

	///
	/// Get a collection
	///
	/// @param database_name
	///   A database name representing a valid Mongo database
	///
	/// @param collection_name
	///   A collection name representing a valid Mongo collection
	///
	/// http://mongocxx.org/api/mongocxx-v3/classmongocxx_1_1collection.html
	///
	const mongocxx::collection get_collection(const std::string &database_name, const std::string &collection_name) const;
};

#endif // CONNECTION