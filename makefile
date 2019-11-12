all: main.o random_func.o
	gcc -o program main.o random_func.o

main.o: main.c random_header.h
	gcc -c main.c

random_func.o: random_func.c random_header.h
	gcc -c random_func.c

run:
	./program

clean:
	rm *.o
	rm *~

memcheck:
	valgrind --leak-check=yes ./program
