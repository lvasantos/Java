CXX = clang++
CXXFLAGS = -pedantic -std=c++11 -Wall -Wextra
LINK.o = $(LINK.cc)

.PHONY: all clean

all: $(EXEC)

main: main.o matrix.o

main.o: main.cpp matrix.cpp

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main *.o
