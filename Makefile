main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o 
	./main < input.cpp

tests: tests.o unindent.o indent.o
	g++ -o tests tests.o unindent.o indent.o

unindent.o: unindent.cpp unindent.h

indent.o: indent.cpp indent.h

main.o: main.cpp indent.h unindent.h

tests.o: tests.cpp doctest.h unindent.h indent.h

clean:
	rm *.o main 
