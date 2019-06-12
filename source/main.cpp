#include "headers.hpp"

int main(const int argc, const char *argv[], const char *envp[])
{
	// Create a connection
	Connection *connection = new Connection();

	// Get a database
	connection->database("test");

	// Get a database and a collection from the database obtained
	mongocxx::collection collection = connection->collection("test", "user");

	// Query the collection
	mongocxx::cursor cursor = collection.find({});

	// Show all documents in the cursor
	for (auto &document : cursor)
		std::cout << bsoncxx::to_json(document) << std::endl;

	return 0;
}