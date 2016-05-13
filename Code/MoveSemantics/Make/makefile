# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -fno-elide-constructors turns off the compiler optimization
CFLAGS  = -fno-elide-constructors -std=c++11

# code path
SRC = ../src

all: matrix matrix_updated

matrix: $(SRC)/matrix.h $(SRC)/matrix.cc
	$(CC) $(CFLAGS) $(SRC)/matrix.cc -o matrix

matrix_updated: $(SRC)/matrix_updated.h $(SRC)/matrix_updated.cc
	$(CC) $(CFLAGS) $(SRC)/matrix_updated.cc -o matrix_updated

clean:
	rm -rf *o matrix\
		  matrix_updated
