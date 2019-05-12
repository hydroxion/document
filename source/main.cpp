#include "headers.hpp"

int main(const int argc, const char *argv[])
{
	// Create a connection
	Connection connection;

	// Get a database
	connection.database("proto-buffer");

	// Get a database and select a collection from the chosen database
	mongocxx::collection collection = connection.collection("proto-buffer", "user");

	// Get all documents from the selected collection
	mongocxx::cursor cursor = collection.find({});

	// Show all documents in cursor
	for (auto document : cursor)
	{
		std::cout << bsoncxx::to_json(document) << "\n";
	}

	return 0;
}