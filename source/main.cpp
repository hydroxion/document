#include "headers.hpp"

int main(const int argc, const char *argv[], const char *envp[])
{
	//
	// Create an user
	//
	// User *user = new User("first name", "second name", "e-mail@email.com", "password");
	//
	User *user = new User();

	//
	// Search an user
	//
	// user->search_one_by_id("");

	//
	// Get an attribute, that has a string value
	//
	// std::cout << "Get string attribute (search one by id): " << user->get_string_attribute("email");

	//
	// Search one document by any attribute, that has a string value
	//
	// user->search_one_by_string("email", "e-mail@email.com");
	//
	// std::cout << "Get string attribute (search one by string): " << user->get_string_attribute("email") << std::endl;

	//
	// Login status
	//
	// std::cout << "Login status: " << user->login_status() << std::endl;

	//
	// Login
	//
	user->login("e-mail@email.com", "password");
	//
	// std::cout << "Login status: " << user->login_status() << std::endl;

	//
	// Delete one document by id
	//
	// user->delete_one_by_id();

	//
	// Update one document attribute, that has a string value, by id
	//
	// user->update_one_by_id("first_name", "First Name");

	return 0;
}