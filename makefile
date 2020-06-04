boid.app : main.o boid.o flock.o pvector.o
	g++ main.o boid.o flock.o pvector.o -std=c++11 -o boid.app -lsfml-graphics -lsfml-window -lsfml-system

main.o : src/main.cpp include/boid.h include/flock.h include/pvector.h
	g++ -std=c++11 -c src/main.cpp

pvector.o : src/pvector.cpp include/pvector.h
	g++ -std=c++11 -c src/pvector.cpp

flock.o : src/flock.cpp include/flock.h include/boid.h
	g++ -std=c++11 -c src/flock.cpp

boid.o : src/boid.cpp include/boid.h
	g++ -std=c++11 -c src/boid.cpp

clean :
	rm *.o boid.app
