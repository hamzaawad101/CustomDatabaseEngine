# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRC = src/main.cpp src/parser.cpp src/execution.cpp

# Header files
HEADERS = include/parser.h include/execution.h

# Output executable
TARGET = dbparser

# Build rule
all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)
