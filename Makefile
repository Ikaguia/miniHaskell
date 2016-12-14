CC = g++ #compiler
FLAGS = -std=c++11 -Wall -Wno-unused-result -O2

PARSER = ast_builder.cpp
OBJS = main.cpp utilFuncs.cpp class_expression.cpp class_var.cpp
TARGET = mh

#minihaskell rule will just execute if one of OBJS file set changes
minihaskell: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(TARGET)

clean:
	find . -type f -name '*.o' -delete

#makefile executes all rule by default
all: minihaskell clean
