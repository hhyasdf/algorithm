test: test.o
	g++ -o test test.o

test.o: test.cpp solution.h
	g++ -c test.cpp -o test.o

clean:
	rm -rf ./*.o ./test
