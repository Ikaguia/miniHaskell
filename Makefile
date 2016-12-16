CC = g++
FLAGS = -std=c++11 -Wall -Wno-unused-result -O2

#modules
OLD_PARSER = ./parser/oldParser.cpp
PARSER = ast_builder.cpp
CORE = util.cpp ./core/class_expression.cpp ./core/class_var.cpp ./core/class_miniHfunc.cpp

MH_MAIN = main.cpp #main executable
MN_TEST = ./test/baselevel_coverageTest.cpp ./test/baselevel_usage.cpp #test executable

#minihaskell rule will just execute if one of CORE or MH_MAIN file set changes
minihaskell: $(CORE) $(MH_MAIN)
	$(CC) $(FLAGS) $(CORE) $(MH_MAIN) -o mh

#Base Level test (see ./test/baselevel_usage.cpp)
bltest: $(CORE) $(OLD_PARSER) $(MN_TEST)
	$(CC) $(FLAGS) $(OLD_PARSER) $(CORE) $(MN_TEST) -o tmh

clean:
	find . -type f -name '*.o' -delete

#makefile executes the 'all' rule by default
all: minihaskell clean
