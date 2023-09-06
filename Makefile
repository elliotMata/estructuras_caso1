all:
	g++ -o news.o news.cpp newsSeeker.cpp doubleList.cpp -lcurl

double:
	g++ doubleList.cpp -o doubleList.o

newsSeeker:
	g++ -o newsSeeker.o newsSeeker.cpp doubleList.cpp