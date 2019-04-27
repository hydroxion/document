#include <iostream>

#include <bsoncxx/json.hpp>

#include <mongocxx/stdx.hpp>

#include <mongocxx/client.hpp>

#include <mongocxx/uri.hpp>

#include <mongocxx/instance.hpp>

///
/// Only one instance must exist for the entirety of the program.
///
/// Don't use static or nest the instance, because it can cause
/// segmentation fault
///
mongocxx::instance instance;

class Connection
{
private:
	std::string mongo_uri{"mongodb://127.0.0.1:27017"};

	mongocxx::client client{mongocxx::uri{this->mongo_uri}};

public:
	///
	/// Constructs a default connection to Mongo
	///
	/// http://mongocxx.org/api/mongocxx-3.3.0/classmongocxx_1_1client.html
	///
	Connection()
	{
	}

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
	Connection(const std::string &mongodb_uri)
	{
		this->mongo_uri = mongo_uri;

		this->client = mongocxx::client{mongocxx::uri{mongodb_uri}};
	}

	///
	/// Destroys a connection
	///
	~Connection()
	{
	}

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
	const mongocxx::database get_database(const std::string &database_name) const
	{
		return this->client[database_name];
	}

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
	const mongocxx::collection get_collection(const std::string &database_name, const std::string &collection_name) const
	{
		return this->get_database(database_name)[collection_name];
	}
};

int main(const int argc, const char *argv[])
{
	// Create a connection
	Connection connection;

	// Get a database
	connection.get_database("proto-buffer");

	// Get a collection from database
	mongocxx::collection collection = connection.get_collection("proto-buffer", "users");

	// Get documents from collection
	mongocxx::cursor cursor = collection.find({});

	for (auto document : cursor)
	{
		std::cout << bsoncxx::to_json(document) << "\n";
	}

	return 0;
}