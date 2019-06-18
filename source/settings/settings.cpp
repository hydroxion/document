#ifndef SETTINGS

#define SETTINGS

#include "settings.hpp"

//
// Connection
//
std::string connection_prefix = "mongodb://";

std::string connection_host = "0.0.0.0";

std::string connection_port = ":27017";

//
// User
//
std::string user_database_name = "proto-buffer";

std::string user_collection_name = "user";

#endif // SETTINGS