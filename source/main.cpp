#include "headers.hpp"

int main(const int argc, const char *argv[])
{
	/// Create a connection
	Connection connection;

	/// Get a database
	connection.get_database("proto-buffer");

	/// Get a collection from database
	mongocxx::collection collection = connection.get_collection("proto-buffer", "users");

	/// Get documents from collection
	mongocxx::cursor cursor = collection.find({});

	for (auto document : cursor)
	{
		std::cout << bsoncxx::to_json(document) << "\n";
	}

	return 0;
}