CPP = g++

OBJS = main.cpp utilFuncs.cpp ast_builder.cpp class_expression.cpp class_var.cpp

FLAGS = -std=c++11 -Wall -Wno-unused-result -O2 -lfl

TARGET = mh

BISON = bison
BISONFLAGS = -d
FLEX = flex

PARSER = parser.tab.c lex.cpp

all:
	$(CPP) $(OBJS) $(PARSER) $(FLAGS) -o $(TARGET)

parser:
	$(BISON) $(BISONFLAGS) parser.y
	$(FLEX) tokenizer.l
