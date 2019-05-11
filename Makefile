COMPILER=g++

FLAGS=-Wall -Werror -std=c++17 -O3

# This compiler configuration uses shared libraries, i.g if the .SO (Linux),
# .DLL (Windows) or .DYLIB (Mac) shared library is not available, the
# executable can't be compiled. You can use static libraries like .A or LIB.
# Change the PKG configuration bellow.
#
# Debug: https://jira.mongodb.org/browse/CXX-1425
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
	rm -rf *.out *.bin *.exe