all:
	gcc aux.c main.c handle.c sio.c stack.c parse.c -o simcalc -lm

debug:
	gcc aux.c main.c handle.c sio.c stack.c parse.c -o simcalc -lm -Wall -g -ggdb3

