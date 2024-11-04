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
	@printf "Compiling the singleton solution file\n"

	@if [ ! -d $(BUILD_DIR) ] ; then \
	mkdir $(BUILD_DIR) ; \
	fi

	@$(CXX) $(CXXFLAGS) -c $(singleton_solution_src_code) -o $(BUILD_DIR)/singleton_solution.o
	@$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/singleton_solution $(BUILD_DIR)/singleton_solution.o

	@if [ -f $(BUILD_DIR)/singleton_solution ] ; then \
	printf "Running the singleton solution\n" ; \
	./build/singleton_solution; \
	fi
	@printf "\n"

.PHONY: factory
factory:
	@printf "Compiling the factory pattern case and solution study files\n"

	@if [ ! -d $(BUILD_DIR) ] ; then \
	mkdir $(BUILD_DIR) ; \
	fi

	@$(CXX) $(CXXFLAGS) -c $(factory_case_src_code) -o $(BUILD_DIR)/factory_case.o
	@$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/factory_case $(BUILD_DIR)/factory_case.o
	@$(CXX) $(CXXFLAGS) -c $(factory_solution_src_code) -o $(BUILD_DIR)/factory_solution.o
	@$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/factory_solution $(BUILD_DIR)/factory_solution.o

	@if [ -f $(BUILD_DIR)/factory_case ] ; then \
	printf "Running the factory case study\n" ; \
	./build/factory_case; \
	fi

	@printf "\n"

	@if [ -f $(BUILD_DIR)/factory_solution ] ; then \
	printf "Running the factory solution\n" ; \
	./build/factory_solution; \
	fi

	@printf "\n"

.PHONY: clean
clean:
	@printf "Cleaning the build directory\n"
	@if [ -d $(BUILD_DIR) ] ; then \
	rm -rf $(BUILD_DIR)/* ; \
	rmdir $(BUILD_DIR); \
	fi
	@printf "\n"

all: clean singleton factory
