boid.app : main.o boid.o
	g++ main.o boid.o -std=c++11 -o boid.app -lsfml-graphics -lsfml-window -lsfml-system

main.o : src/main.cpp include/boid.h
	g++ -std=c++11 -c src/main.cpp

boid.o : src/boid.cpp include/boid.h
	g++ -std=c++11 -c src/boid.cpp

clean :
	rm *.o boid.app
