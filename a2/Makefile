sample: temperature.o testmain.o
	g++ temperature.o testmain.o -o sample

testmain.o: testmain.cpp
	g++ -c testmain.cpp

temperature.o: temperature.cpp
	g++ -c temperature.cpp                          

clean:
	rm -rf *o sample
