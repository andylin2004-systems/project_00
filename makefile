all: main.o myTunes.o
	gcc -o test main.o myTunes.o songNode.o

run:
	./test

main.o: main.c myTunes.h
	gcc -c main.c

myTunes.o: myTunes.c myTunes.h songNode.h
	gcc -c myTunes.c

songNode.o: songNode.c songNode.h
	gcc -c songNode.c