CPP = g++

OBJS = main.cpp utilFuncs.cpp ast_builder.cpp class_expression.cpp class_var.cpp

FLAGS = -std=c++14 -Wall -Wno-unused-result -O2

TARGET = mh

all:
	$(CPP) $(FLAGS) $(OBJS) -o $(TARGET)