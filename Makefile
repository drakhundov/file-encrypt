# Compiler
CXX = clang++
# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Werror
# Source files
SRCS = $(wildcard src/*.cpp)
# Object files
OBJS = $(patsubst src/%.cpp, build/obj/%.o, $(SRCS))
# Executable name
TARGET = bin/encrypt

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $^

build/obj/%.o: src/%.cpp
	@mkdir -p build/obj
	$(CXX) $(CXXFLAGS) -Iinclude -o $@ -c $<

run: $(TARGET)
	@./$(TARGET) $(ARGS)

clean:
	rm -f build/obj/*.o $(TARGET)

.PHONY: all clean
