CXX = g++
CXXFLAGS = -Wall -g -std=c++17


SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/app

.PHONY: factory
factory:
	@echo "Compiling factory pattern"
	mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/factory_pattern.cpp -o $(BUILD_DIR)/factory.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(BUILD_DIR)/factory.o

.PHONY: clean
clean:
	@echo "Cleaning"
	rm -rf build
