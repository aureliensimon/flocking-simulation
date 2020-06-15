#ifndef FLOCK_H
#define FLOCK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "obstacle.h"
#include "boid.h"

using namespace std;

class Boid;

class Flock {
    public :
        Flock (int nbinit = 0) : numberBoids(nbinit) {}
        ~Flock() {}

        void settlement();
        void update(vector<Obstacle>);
        void show(sf::RenderWindow *);
        void addBoid(sf::Vector2i);
        vector<Boid> getBoids () const { return boids; }
        int getNumberBoids () const { return numberBoids; }
    protected :
        int numberBoids;
        vector<Boid> boids;
};

#endif