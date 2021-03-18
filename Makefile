main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o 
	./main < testing.cpp

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

unindent.o: unindent.cpp unindent.h

indent.o: indent.cpp indent.h

main.o: main.cpp indent.h unindent.h

tests.o: tests.cpp doctest.h funcs.h

clean:
	rm *.o main 
