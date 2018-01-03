program: main.o dewarping.o
	g++ main.o dewarping.o -std=c++11 -fopenmp `pkg-config --cflags --libs opencv` -o program

main.o: main.cpp
	g++ main.cpp -std=c++11 -fopenmp `pkg-config --cflags --libs opencv` -c

dewarping.o: dewarping.hpp dewarping.cpp
	g++ dewarping.cpp -std=c++11 -O3 -fopenmp `pkg-config --cflags --libs opencv` -c

clean:
	rm -f *.o
	rm -f program