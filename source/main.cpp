#include "headers.hpp"

int main(const int argc, const char *argv[], const char *envp[])
{
	//
	// Create an user
	//
	// User *user = new User("first name", "second name", "e-mail@email.com", "password");
	//
	// User *user = new User();

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
	// user->login("e-mail@email.com", "password");
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

	//
	// Create a document
	//
	// std::vector<std::string> category = {"category1", "category2"};
	//
	// std::vector<std::string> keyword = {"keyword1", "keyword2"};
	//
	// Document *document = new Document("id", "title", "type", "idiom", category, keyword);
	//
	// Document *document = new Document();

	//
	// Search a document
	//
	// document->search_one_by_id("id");

	//
	// Search one document by any attribute, that has a string value
	//
	// document->search_one_by_string("idiom", "idiom");

	//
	// Get an attribute, that has a string value
	//
	// std::cout << "Get string attribute (search one by id): " << document->get_string_attribute("title") << std::endl;

	//
	//
	// Get an document id
	//
	// std::cout << "Document id: " << document->get_document_oid("_id") << std::endl;

	//
	//
	// Get an document date attribute
	//
	// std::cout << "Document created at: " << document->get_document_iso_date("created_at") << std::endl;

	//
	// Delete one document by id
	//
	// document->delete_one_by_id();

	//
	// Upload a file to database
	//
	// DocumentFile *file = new DocumentFile("path");
	//
	// DocumentFile *file = new DocumentFile();

	//
	// Search a document
	//
	// file->search_one_by_id("id");

	//
	// Search one document by any attribute, that has a string value
	//
	// file->search_one_by_string("name", "presentation.pdf");

	//
	// Get an attribute, that has a string value
	//
	// std::cout << "Get string attribute (search one by id): " << file->get_string_attribute("name") << std::endl;

	//
	//
	// Get an document id
	//
	// std::cout << "Document id: " << file->get_document_oid("_id") << std::endl;

	//
	// Delete one document by id
	//
	// file->delete_one_by_id();

	//
	// Download a file from database
	//
	// file->download("./");

	return 0;
}