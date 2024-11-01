CXX = g++
CXXFLAGS = -Wall -g -std=c++17

SRC_DIR = src
BUILD_DIR = build
CASE_TARGET = $(BUILD_DIR)/case_app
SOLUTION_TARGET = $(BUILD_DIR)/solution_app

singleton_solution_src_code :=
factory_case_src_code :=
factory_solution_src_code :=

include $(SRC_DIR)/factory_pattern/package.mk
include $(SRC_DIR)/singleton_pattern/package.mk

default: all

.PHONY: singleton
singleton:
	@echo "Compiling the factory pattern case and solution study files"
	@mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(singleton_solution_src_code) -o $(BUILD_DIR)/singleton_solution.o
	$(CXX) $(CXXFLAGS) -o $(SOLUTION_TARGET) $(BUILD_DIR)/singleton_solution.o

.PHONY: factory
factory:
	@echo "Compiling the factory pattern case and solution study files"
	@mkdir $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -c $(factory_case_src_code) -o $(BUILD_DIR)/factory_case.o
	@$(CXX) $(CXXFLAGS) -o $(CASE_TARGET) $(BUILD_DIR)/factory_case.o
	@$(CXX) $(CXXFLAGS) -c $(factory_solution_src_code) -o $(BUILD_DIR)/factory_solution.o
	@$(CXX) $(CXXFLAGS) -o $(SOLUTION_TARGET) $(BUILD_DIR)/factory_solution.o

.PHONY: clean
clean:
	@echo "Cleaning the build directory"
	@rm -rf build/*
	@rmdir build

.PHONY: run
run:
	@if [ -f build/case_app ] ; then \
	echo "Running the case study" ; \
	./build/case_app ; \
	fi

all: clean factory run
