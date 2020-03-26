Lab6: main.o Executive.o BST.o BNode.o
	g++ -std=c++11 -g -Wall main.o Executive.o BST.o BNode.o -o Lab6

main.o: main.cpp Executive.h BNode.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp BST.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

BST.o: BST.cpp BNode.h
	g++ -std=c++11 -g -Wall -c BST.cpp

BNode.o: BNode.cpp
	g++ -std=c++11 -g -Wall -c BNode.cpp

clean:
	rm *.o Lab6
