#include <cstdint>

#include <iostream>

#include <vector>

#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>

#include <mongocxx/stdx.hpp>

#include <mongocxx/uri.hpp>

#include <mongocxx/instance.hpp>

int main(const int argc, const char *argv[]) {
    mongocxx::instance instance{};

    mongocxx::uri uri("mongodb://0.0.0.0:27017");
    
    mongocxx::client client(uri);

    mongocxx::database db = client["admin"];

    return 0;
}