all: reversi

reversi: check_validmoves.o updating_moves.o main.o
	g++ -pedantic-errors -std=c++11 $^ -o reversi

main.o: main.cpp main.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

function3.o: check_validmoves.cpp updating_moves.h 
	g++ -pedantic-errors -std=c++11 -c check_validmoves.cpp

function4.o: updating_moves.cpp updating_moves.h 
	g++ -pedantic-errors -std=c++11 -c updating_moves.cpp

clean:
	rm -f  *.o reversi

tar:
	tar -czvf *.cpp *.h

.PHONY: clean tar
