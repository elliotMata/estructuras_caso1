all:
	g++ -o main.o main.cpp newsSeeker.cpp doubleList.cpp

double:
	g++ doubleList.cpp -o doubleList.o

news:
	g++ -o newsSeeker.o newsSeeker.cpp doubleList.cpp