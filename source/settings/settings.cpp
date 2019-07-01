#ifndef SETTINGS

#define SETTINGS

#include "settings.hpp"

//
// Connection
//
std::string connection_prefix{"mongodb://"};

std::string connection_host{"0.0.0.0"};

std::string connection_port{":27017"};

//
// User
//
std::string user_database_name{"proto-buffer"};

std::string user_collection_name{"user"};

//
// Document
//
std::string document_database_name{"proto-buffer"};

std::string document_collection_name{"document"};

//
// Document file
//
std::string document_file_database_name{"proto-buffer"};

std::string document_file_collection_name{"file"};

std::string document_file_valid_format{"pdf"};

#endif // SETTINGS