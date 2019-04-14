COMPILER=g++

FLAGS=-Wall -Werror -std=c++17 -O3

# Shared libraries https://jira.mongodb.org/browse/CXX-1425
LIBRARIES=`pkg-config --libs libbson-1.0 libmongoc-1.0 libbsoncxx libmongocxx` -Wl,-rpath,/usr/local/lib

INCLUDES=`pkg-config --cflags libbson-1.0 libmongoc-1.0 libbsoncxx libmongocxx`

SOURCES=source/classes/*/*.cpp

EXECUTABLE=Proto-buffer.out

all: executable

executable: $(SOURCES)
	$(COMPILER) $(SOURCES) -o $(EXECUTABLE) $(FLAGS) $(INCLUDES) $(LIBRARIES)

run:
	./$(EXECUTABLE)

clean:
	rm -rf ./*.out