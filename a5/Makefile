sample: MyInt.o main.o
	g++ MyInt.o main.o -o sample.x

MyInt.o: MyInt.cpp
	g++ -c MyInt.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o sample
