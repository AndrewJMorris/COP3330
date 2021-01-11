sample: studentlist.o student.o main.o
	g++ studentlist.o student.o main.o -o sample

studentlist.o: studentlist.cpp
	g++ -c studentlist.cpp

student.o: student.cpp
	g++ -c student.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm -rf *o sample
