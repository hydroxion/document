#include "headers.hpp"

int main(const int argc, const char *argv[], const char *envp[])
{
	//
	// Create an user
	//
	User *user = new User("First Name", "Second Name", "e-mail@email.com", "password");

	//
	// Search for an user
	//
	user->search_one_by_id("5d0bb7042a554e44db53f142");

	return 0;
}