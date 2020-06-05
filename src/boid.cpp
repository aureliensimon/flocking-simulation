#include "../include/boid.h"

void Boid::update () {
    position.add(velocity);
    velocity.add(acceleration);
    edges();
    getNeighbours();
}

void Boid::show (sf::RenderWindow * window) {
    sf::CircleShape shape(10, 3);
    shape.setFillColor(sf::Color(getColorR(), getColorG(), getColorB(), 255));
    shape.setPosition(position.getX(), position.getY());
    window->draw(shape);
}

void Boid::edges () {
    if (position.getX() < 0) {
        position.set(WIDTH, position.getY(), position.getZ());
    } else if (position.getX() > WIDTH) {
        position.set(0, position.getY(), position.getZ());
    }
    if (position.getY() < 0) {
        position.set(position.getX(), HEIGHT, position.getZ());
    } else if (position.getY() > HEIGHT) {
        position.set(position.getX(), 0, position.getZ());
    }
}

vector<Boid> Boid::getNeighbours () {
    vector<Boid> neighbours;
    
    for (Boid & boid : flock->getBoids()) {
        if (!this->position.compare(boid.position) && this->position.dist(boid.position) < this->fov) neighbours.push_back(boid);
    }

    return neighbours;
}