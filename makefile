CXX = g++
CXXFLAGS = -Wall -g -std=c++17

SRC_DIR = src
BUILD_DIR = build

singleton_solution_src_code :=
factory_case_src_code :=
factory_solution_src_code :=

include $(SRC_DIR)/factory_pattern/package.mk
include $(SRC_DIR)/singleton_pattern/package.mk

default: all

.PHONY: singleton
singleton:
	@echo ""
	@echo "Compiling the singleton pattern study file"

	@if [ ! -d $(BUILD_DIR) ] ; then \
	mkdir $(BUILD_DIR) ; \
	fi

	@$(CXX) $(CXXFLAGS) -c $(singleton_solution_src_code) -o $(BUILD_DIR)/singleton_solution.o
	@$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/singleton_solution $(BUILD_DIR)/singleton_solution.o

	@if [ -f $(BUILD_DIR)/singleton_solution ] ; then \
	echo "Running the singleton solution" ; \
	./build/singleton_solution; \
	fi

.PHONY: factory
factory:
	@echo ""
	@echo "Compiling the factory pattern case and solution study files"

	@if [ ! -d $(BUILD_DIR) ] ; then \
	mkdir $(BUILD_DIR) ; \
	fi

	@$(CXX) $(CXXFLAGS) -c $(factory_case_src_code) -o $(BUILD_DIR)/factory_case.o
	@$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/factory_case $(BUILD_DIR)/factory_case.o
	@$(CXX) $(CXXFLAGS) -c $(factory_solution_src_code) -o $(BUILD_DIR)/factory_solution.o
	@$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/factory_solution $(BUILD_DIR)/factory_solution.o

	@if [ -f $(BUILD_DIR)/factory_case ] ; then \
	echo "" \
	echo "Running the factory case study" ; \
	./build/factory_case; \
	fi

	@if [ -f $(BUILD_DIR)/factory_solution ] ; then \
	echo "" \
	echo "Running the factory solution" ; \
	./build/factory_solution; \
	fi

.PHONY: clean
clean:
	@echo ""
	@echo "Cleaning the build directory"
	@if [ -d $(BUILD_DIR) ] ; then \
	rm -rf $(BUILD_DIR)/* ; \
	rmdir $(BUILD_DIR); \
	fi

all: clean singleton factory
