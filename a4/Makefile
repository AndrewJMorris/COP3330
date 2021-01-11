sample: book.o store.o menu.o
	g++ book.o store.o menu.o -o sample

testbook.o: testbook.cpp
	g++ -c testbook.cpp

book.o: book.cpp
	g++ -c book.cpp 

menu.o: menu.cpp
	g++ -c menu.cpp

store.o: store.cpp
	g++ -c store.cpp

clean:
	rm -rf *o sample
