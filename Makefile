CC = g++
FLAGS = -std=c++11 -Wall -Wno-unused-result -O2 -lfl

PARSER = ast_builder.cpp parser.tab.c lex.cpp
CORE = util.cpp ./core/class_expression.cpp ./core/class_var.cpp


MH_MAIN = main.cpp #main executable
MN_TEST = ./test/baselevel_coverageTest.cpp ./test/baselevel_usage.cpp #test executable

TARGET = mh

BISON = bison
BISONFLAGS = -d
FLEX = flex


#minihaskell rule will just execute if one of CORE or MH_MAIN file set changes
minihaskell: $(CORE) $(MH_MAIN)
	$(CC) $(CORE) $(PARSER) $(MH_MAIN) $(FLAGS) -o $(TARGET)

#Base Level test (see ./test/baselevel_usage.cpp)
bltest: $(CORE) $(MN_TEST)
	$(CC) $(FLAGS) $(CORE) $(MN_TEST) -o tmh

clean:
	find . -type f -name '*.o' -delete


all:
	$(CPP) $(OBJS) $(PARSER) $(FLAGS) -o $(TARGET)

parser:
	$(BISON) $(BISONFLAGS) parser/parser.y
	$(FLEX) parser/tokenizer.l

clear_parser:
	rm lex.cpp lex.h parser.tab.c parser.tab.h

#makefile executes the 'all' rule by default
all: minihaskell clean
