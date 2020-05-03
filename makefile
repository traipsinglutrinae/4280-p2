run: main.o token.o testTree.o scanner.o parser.o
	g++ main.o token.o testTree.o scanner.o parser.o -o frontEnd -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

token.o: token.cpp
	g++ -c token.cpp -std=c++11

testTree.o: testTree.cpp
	g++ -c testTree.cpp -std=c++11

scanner.o: scanner.cpp
	g++ -c scanner.cpp -std=c++11

parser.o: parser.cpp
	g++ -c parser.cpp -std=c++11

clean:
	rm -rf *.o frontEnd
