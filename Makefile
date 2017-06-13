CC = g++

FLAGS = -Wall -std=c++11 -g

SRC = main.cpp parseat.cpp strategy.cpp circprop.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = parseat

$(TARGET) : $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

.PHONY: clear

clear:
	rm *.o
