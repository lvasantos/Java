# Compilador e flags
# CXX = g++
CXX = clang++
CXXFLAGS = -pedantic -std=c++11 -Wall -Wextra

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build


SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/matrix.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

EXEC = $(BUILD_DIR)/main

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
