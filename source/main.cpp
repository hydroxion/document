#include "headers.hpp"

int main(const int argc, const char *argv[], const char *envp[])
{
	//
	// Change protected to public to use the code below, in the
	// connection.hpp
	//

	//
	// Create a connection
	//
	// Connection *connection = new Connection();

	//
	// Get a database
	//
	// connection->database("proto-buffer");

	//
	// Get a database and a collection from the obtained database
	//
	// mongocxx::collection collection = connection->collection("proto-buffer", "user");

	//
	// Query the collection
	//
	// mongocxx::cursor cursor = collection.find({});

	//
	// Show all documents in the cursor
	// for (auto &document : cursor)
	// 	std::cout << bsoncxx::to_json(document) << std::endl;

	//
	// Create an user
	//
	User *user = new User("First Name", "Second Name", "e-mail@email.com", "password");

	//
	// Search for an user
	//
	user->search_one_by_id();

	return 0;
}