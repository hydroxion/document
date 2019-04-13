# Project settings
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)  # CMake version

PROJECT(Proto-buffer CXX)  # Project name and language

SET(CMAKE_CXX_STANDARD 17)  # Language C++ 17 standard

set(CMAKE_CXX_EXTENSIONS OFF)  # Disable C++ 17 extensions

# Libraries settings
FIND_PACKAGE(libmongocxx REQUIRED)

FIND_PACKAGE(libbsoncxx REQUIRED)

INCLUDE_DIRECTORIES(${LIBMONGOCXX_INCLUDE_DIR})

INCLUDE_DIRECTORIES(${LIBBSONCXX_INCLUDE_DIR})

INCLUDE_DIRECTORIES("/usr/local/include/mongocxx/v_noabi")

INCLUDE_DIRECTORIES("/usr/local/include/bsoncxx/v_noabi")

INCLUDE_DIRECTORIES("/usr/local/include/libmongoc-1.0")

INCLUDE_DIRECTORIES("/usr/local/include/libbson-1.0")

# Executables settings
ADD_EXECUTABLE(${PROJECT_NAME} ./source/classes/connection/connection.cpp)