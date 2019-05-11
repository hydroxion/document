#include "headers.hpp"

int main(const int argc, const char *argv[])
{
	/// Change the method' visibility on client to get documents from the Mongo,
	/// without the class document, user, etc

	/// Create a connection
	Connection connection;

	/// Get a database
	connection.get_database("proto-buffer");

	/// Get a database and select a collection from the database
	mongocxx::collection collection = connection.get_collection("proto-buffer", "users");

	/// Get documents from the selected collection
	mongocxx::cursor cursor = collection.find({});

	/// Show all documents present on cursor
	for (auto document : cursor)
	{
		std::cout << bsoncxx::to_json(document) << "\n";
	}

	return 0;
}