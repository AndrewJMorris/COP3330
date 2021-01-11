sample: time.o testmain.o
	g++ time.o testmain.o -o sample

testmain.o: testmain.cpp
	g++ -c testmain.cpp

time.o: time.cpp
	g++ -c time.cpp

clean:
	rm -rf *o sample
