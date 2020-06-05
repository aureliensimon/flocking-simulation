#ifndef BOID_H
#define BOID_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

#include "flock.h"
#include "pvector.h"

#define WIDTH 1500
#define HEIGHT 750

using namespace std;

typedef struct {
    int r;
    int g;
    int b;
} Rgb;

class Flock;

class Boid {
    public :
        Boid(Flock * finit, int xinit = 0, int yinit = 0) {
            position.set(WIDTH/2.f, HEIGHT/2.f);
            velocity.set(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/max_speed)) - max_speed/2, static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/max_speed)) - max_speed/2);
            acceleration.set(0, 0);

            color.r = rand() % 255;
            color.g = rand() % 255;
            color.b = rand() % 255;

            flock = finit;
        }
        ~Boid() {}

        int getColorR() const { return color.r; }
        int getColorG() const { return color.g; }
        int getColorB() const { return color.b; }

        void update();
        void show(sf::RenderWindow *);
        void edges();
        vector<Boid> getNeighbours();

    protected:
        PVector position;
        PVector velocity;
        PVector acceleration;
        
        int fov = 100;
        int max_speed = 2;
        int max_force = 10;
        Rgb color;
        Flock * flock;
};

#endif