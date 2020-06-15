#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "pvector.h"

using namespace std;

class Obstacle {
    public :
       Obstacle(sf::Vector2i positionMouse) {
           position.set(positionMouse.x - radius, positionMouse.y  - radius);
       }
       ~Obstacle() {}
        
        PVector getPosition () const { return position; }
        
        void show(sf::RenderWindow *);
    protected :
        double radius = 10;
        PVector position;
};

#endif