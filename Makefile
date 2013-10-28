all: morse

morse: stack.o morse.o
	gcc stack.o morse.o -o morse -lm

stack.o: stack.c
	gcc -Wall -c stack.c

morse.o: morse.c
	gcc -Wall -c morse.c

clean:
	rm morse
	rm *.o