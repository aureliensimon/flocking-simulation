#ifndef BOID_H
#define BOID_H

#include <iostream>

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
            velocity.x = 1;
            velocity.y = 0.75;
            acceleration.x = 0;
            acceleration.y = 0;

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
    
    protected:
        Vect position;
        Vect velocity;
        Vect acceleration;
        
        Rgb color;
};

#endif