all: tetris

tetris: main.o board.o piece.o record.o
	gcc main.o board.o piece.o record.o -o tetris

main.o: main.c board.h piece.h color.h record.h
	gcc -c main.c -o main.o -Wall 

board.o: board.c color.h
	gcc -c board.c -o board.o -Wall

piece.o: piece.c color.h
	gcc -c piece.c -o piece.o -Wall

record.o: record.c record.h
	gcc -c record.c -o record.o -Wall

clean:
	rm -f *.o
	rm score.txt
