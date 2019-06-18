#include <string>

//
// If some resource that is configured here doesn't exist in the
// Mongo database, when the application runs with the current
// setting, all the resources are going to be created
//

//
// Connection
//
extern std::string connection_prefix;

extern std::string connection_host;

extern std::string connection_port;

//
// User
//
extern std::string user_database_name;

extern std::string user_collection_name;