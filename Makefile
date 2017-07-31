program: main.cpp
	g++ main.cpp -std=c++11 -fopenmp `pkg-config --cflags --libs opencv` -o program

clean:
	rm -f *.o
	rm -f program