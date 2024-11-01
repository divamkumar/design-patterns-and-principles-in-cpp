CXX = g++
CXXFLAGS = -Wall -g -std=c++17

SRC_DIR = src
BUILD_DIR = build
CASE_TARGET = $(BUILD_DIR)/case_app
SOLUTION_TARGET = $(BUILD_DIR)/solution_app

factory_case_src_code :=
factory_solution_src_code :=

include $(SRC_DIR)/factory_pattern/package.mk

.PHONY: factory
factory:
	@echo "Compiling the factory pattern case and solution study files"
	mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(factory_case_src_code) -o $(BUILD_DIR)/factory_case.o
	$(CXX) $(CXXFLAGS) -o $(CASE_TARGET) $(BUILD_DIR)/factory_case.o
	$(CXX) $(CXXFLAGS) -c $(factory_solution_src_code) -o $(BUILD_DIR)/factory_solution.o
	$(CXX) $(CXXFLAGS) -o $(SOLUTION_TARGET) $(BUILD_DIR)/factory_solution.o

.PHONY: clean
clean:
	@echo "Cleaning the build directory"
	cd build/
	rm -rf *
	cd ..

.PHONY: run
run:
	@echo "Running the case study"
	./build/case_app
	@echo "Running the solution to the case study"
	./build/solution_app

all: clean factory run
