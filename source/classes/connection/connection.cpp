#include <cstdint>

#include <iostream>

#include <vector>

#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>

#include <mongocxx/stdx.hpp>

#include <mongocxx/uri.hpp>

#include <mongocxx/instance.hpp>

class Connection
{
    private: 
        static mongocxx::instance instance{};

        mongocxx::client client{mongocxx::uri("mongodb://0.0.0.0:27017")};
};

int main(const int argc, const char *argv[])
{
    Connection connection;

    return 0;
}