#ifndef FLOCK_H
#define FLOCK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "../include/boid.h"

class Flock {
    public :
        Flock (int nbinit = 0) : numberBoids(nbinit) {}
        ~Flock() {}

        void settlement();
        void update();
        vector<Boid> getBoids () const { return boids; };
    protected :
        int numberBoids;
        vector<Boid> boids;
};

#endif