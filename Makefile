COMPILER=g++

FLAGS=-Wall -Werror -std=c++17 -O3

# This compiler configuration uses shared libraries, i.g if the .SO (Linux),
# .DLL (Windows) or .DYLIB (Mac) shared libraries are not available, the
# executable can't be compiled and an error is issued. You can use static
# libraries like .A or LIB, to do so, set the libraries in the pkg configuration
# below.
#
# More details: https://jira.mongodb.org/browse/CXX-1425
LIBRARIES=`pkg-config --libs libbson-1.0 libmongoc-1.0 libbsoncxx libmongocxx` -Wl,-rpath,/usr/local/lib

INCLUDES=`pkg-config --cflags libbson-1.0 libmongoc-1.0 libbsoncxx libmongocxx`

SOURCES=source/classes/*/*.cpp source/classes/*/*.hpp source/*.cpp

EXECUTABLE=proto-buffer.bin

all: executable

executable: $(SOURCES)
	$(COMPILER) $(SOURCES) -o $(EXECUTABLE) $(FLAGS) $(INCLUDES) $(LIBRARIES)

run:
	./$(EXECUTABLE)

clean:
	rm -rf ./*.out ./*.bin ./*.exe