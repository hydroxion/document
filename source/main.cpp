#include "headers.hpp"

int main(const int argc, const char *argv[], const char *envp[])
{
	// Create a connection
	Connection *connection = new Connection();

	// Get a database
	connection->database("database-name");

	// Get a database and a collection from the obtained database
	mongocxx::collection collection = connection->collection("database-name", "collection-name");

	// Query the collection
	mongocxx::cursor cursor = collection.find({});

	// Show all documents in the cursor
	for (auto &document : cursor)
		std::cout << bsoncxx::to_json(document) << std::endl;

	// Create user
	// User *user = new User("First Name", "Second Name", "e-mail@email.com", "password");

	return 0;
}