CPP = g++

OBJS = main.cpp class_miniHfunc.cpp utilFuncs.cpp runExpr.cpp operators.cpp

FLAGS = -std=c++14 -Wall -Wno-unused-result -O2

TARGET = mh

all:
	$(CPP) $(FLAGS) $(OBJS) -o $(TARGET)