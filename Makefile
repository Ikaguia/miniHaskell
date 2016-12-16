CC = g++
FLAGS = -std=c++11 -Wall -Wno-unused-result -O2 -lfl

PARSER = ast_builder.cpp
CORE = util.cpp ./core/class_expression.cpp ./core/class_var.cpp

MH_MAIN = main.cpp #main executable
MN_TEST = ./test/baselevel_usage.cpp #test executable

BISON = bison
BISONFLAGS = -d
FLEX = flex

PARSER = parser.tab.c lex.cpp

#minihaskell rule will just execute if one of CORE or MH_MAIN file set changes
minihaskell: $(CORE) $(MH_MAIN)
	$(CC) $(FLAGS) $(CORE) $(MH_MAIN) -o mh

#Base Level test (see ./test/baselevel_usage.cpp)
bltest: $(CORE) $(MN_TEST)
	$(CC) $(FLAGS) $(CORE) $(MN_TEST) -o tmh

clean:
	find . -type f -name '*.o' -delete


all:
	$(CPP) $(OBJS) $(PARSER) $(FLAGS) -o $(TARGET)

parser:
	$(BISON) $(BISONFLAGS) parser.y
	$(FLEX) tokenizer.l

#makefile executes the 'all' rule by default
all: minihaskell clean
