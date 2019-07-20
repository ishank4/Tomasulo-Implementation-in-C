# the compiler: compiler g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -std=c++11 -g -Wall


all:
	$(CC) $(CFLAGS) main.cpp Instruction.cpp RegisterStatus.cpp ReservationStation.cpp -o tomasulo

