CFLAGS=-g -ggdb

all: input.o  print.o  main.o

	gcc -g -ggdb -o test main.o input.o print.o

main.o:main.c
	gcc $(CFLAGS) -c main.c

clean:
	rm *.o test

