CXX = clang++
CXXFLAGS = -Wall -Werror -g -std=c++17

OUTPUTMAIN = main
OUTPUTTEST = test

SRCS = UnionFind.cpp PQueue.cpp Graph.cpp Algorithms.cpp

MAIN = main.cpp
TEST = Test.cpp

OBJS = $(SRCS:.cpp=.o)

MAINS = $(OBJS) $(MAIN:.cpp=.o)

TESTS = $(OBJS) $(TEST:.cpp=.o)


.PHONY: main test valgrind clean

main: $(MAINS)
	$(CXX) $(CXXFLAGS) -o $(OUTPUTMAIN) $(MAINS)

test: $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(OUTPUTTEST) $(TESTS)

valgrind: $(OUTPUTTEST) $(OUTPUTMAIN)
	valgrind --leak-check=full ./$(OUTPUTTEST)
	valgrind --leak-check=full ./$(OUTPUTMAIN)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
ifeq ($(OS),Windows_NT)
	del /F $(OUTPUTMAIN).exe $(OUTPUTTEST).exe $(OBJS) $(MAINS) $(TESTS)
else
	rm -f $(OUTPUTMAIN) $(OUTPUTTEST) $(OBJS) $(MAINS) $(TESTS)
endif