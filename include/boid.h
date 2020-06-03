#ifndef BOID_H
#define BOID_H

#include <iostream>

using namespace std;

typedef struct {
    double x;
    double y;
} Vect;

class Boid {
    public :
        Boid(int xinit = 0, int yinit = 0) {
            position.x = xinit;
            position.y = yinit;

            velocity.x = 2;
            velocity.y = 0.5;

            acceleration.x = 0;
            acceleration.y = 0;
        }
        ~Boid() {}

        int getPositionX() const { return position.x; }
        int getPositionY() const { return position.y; }

        void update();
    
    protected:
        Vect position;
        Vect velocity;
        Vect acceleration;
};

#endif