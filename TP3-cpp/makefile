CXX = clang++
CXXFLAGS = -pedantic -std=c++11 -Wall -Wextra
LINK.o = $(LINK.cc)

.PHONY: all clean

all: main

main: main.o

main.o: main.cpp

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main *.o
