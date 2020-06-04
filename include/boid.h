#ifndef BOID_H
#define BOID_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

typedef struct {
    double x;
    double y;
} Vect;

typedef struct {
    int r;
    int g;
    int b;
} Rgb;

class Boid {
    public :
        Boid(int xinit = 0, int yinit = 0) {
            position.x = xinit;
            position.y = yinit;
            velocity.x = fmod(rand(), 1) - 0.5;
            velocity.y = fmod(rand(), 1) - 0.5;
            acceleration.x = fmod(rand(), 1) - 0.5;
            acceleration.y = fmod(rand(), 1) - 0.5;

            color.r = rand() % 255;
            color.g = rand() % 255;
            color.b = rand() % 255;
        }
        ~Boid() {}

        int getPositionX() const { return position.x; }
        int getPositionY() const { return position.y; }
        int getColorR() const { return color.r; }
        int getColorG() const { return color.g; }
        int getColorB() const { return color.b; }

        void update();
        void show(sf::RenderWindow *);
        void edges();

    protected:
        Vect position;
        Vect velocity;
        Vect acceleration;
        
        Rgb color;
};

#endif