#ifndef BOID_H
#define BOID_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

#include "flock.h"
#include "pvector.h"

#define WIDTH 600
#define HEIGHT 600

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
            position.set(rand() % WIDTH/2, rand() % HEIGHT/2);
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

        PVector getPosition () const { return position; }

        void update();
        void show(sf::RenderWindow *);
        void showFov(sf::RenderWindow *);
        void edges();
        vector<Boid> getNeighbours();

        void align(vector<Boid>);

    protected:
        PVector position;
        PVector velocity;
        PVector acceleration;
        
        int fov = 45;
        int max_speed = 5;
        double max_force = 0.05;
        Rgb color;
        Flock * flock;
};

#endif