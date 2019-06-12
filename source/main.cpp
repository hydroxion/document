#include "headers.hpp"

int main(const int argc, const char *argv[])
{
	// Create a connection
	Connection *connection = new Connection();

	// Get a database
	connection->database("test");

	// Get a database and select a collection from the chosen database
	mongocxx::collection collection = connection->collection("test", "user");

	// Get all documents from the selected collection
	mongocxx::cursor cursor = collection.find({});

	// Show all documents in cursor
	for (auto document : cursor)
	{
		std::cout << bsoncxx::to_json(document) << "\n";
	}

	// Stream is not available, besides basic, its possible to use the
	// core (/usr/local/include/bsoncxx/v_noabi/bsoncxx/builder/core.hpp)
	// to build a specific abstraction
	auto builder = bsoncxx::builder::stream::document{};

	return 0;
}