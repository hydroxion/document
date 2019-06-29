#include "headers.hpp"

int main(const int argc, const char *argv[], const char *envp[])
{
	//
	// Create an user
	//
	// User *user = new User("First Name", "Second Name", "e-mail@email.com", "password");
	//
	User *user = new User();

	//
	// Search for an user
	//
	user->search_one_by_id("5d0afc602a554e628e63ddb2");

	//
	// Get an attribute from the document found in the
	// search above
	//
	std::cout << "Get string attribute (search one by id): " << user->get_string_attribute("first_name") << std::endl << std::endl;

	//
	// Search for a document using any attribute that has a string value
	//
	user->search_one_by_string("email", "e-mail@email.com");

	std::cout << "Get string attribute (search one by string): " << user->get_string_attribute("email") << std::endl;

	//
	// Login
	//
	user->login("e-mail@email.com", "password");

	return 0;
}