CPP = g++

OBJS = main.cpp class_miniHfunc.cpp utilFuncs.cpp runExpr.cpp
OBJS_TEST = tests.cpp class_miniHfunc.cpp utilFuncs.cpp runExpr.cpp

FLAGS = -std=c++14 -Wall -Wno-unused-result -O2

TARGET = mh
TEST = test

all:
	$(CPP) $(FLAGS) $(OBJS) -o $(TARGET)
test:
	$(CPP) $(FLAGS) $(OBJS_TEST) -o $(TEST)