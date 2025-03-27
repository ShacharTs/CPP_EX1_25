# Compiler
CXX = C:/msys64/mingw64/bin/g++


# Compiler flags: enable all warnings, debug info, and use C++17
CXXFLAGS = -Wall -g -std=c++17

# Name of the target executable
TARGET = main

# Source files (adjust paths if they are in subdirectories)
SRCS = Graph.cpp Algorithms.cpp Test.cpp

# Object files (automatically derived from SRCS)
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the target executable and run it
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Pattern rule to compile .cpp files into .o files.
# (Make sure to use a TAB at the beginning of the command line)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files
clean:
	del /F $(TARGET_DEL) $(OBJS)

