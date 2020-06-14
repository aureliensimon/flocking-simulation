#include "../include/boid.h"

void Boid::update () {
    position.add(velocity);
    velocity.add(acceleration);
    velocity.limit(max_speed);
    this->acceleration.set(0, 0, 0);
    edges();

    vector<Boid> neighbours = getNeighbours();
    align(neighbours);
    cohesion(neighbours);
}

void Boid::show (sf::RenderWindow * window) {
    sf::CircleShape body(10, 3);
    body.setFillColor(sf::Color(getColorR(), getColorG(), getColorB(), 255));
    body.setPosition(position.getX(), position.getY());
    window->draw(body);
}

void Boid::showFov (sf::RenderWindow * window) {
    sf::CircleShape vision(fov);
    vision.setFillColor(sf::Color(50, 50, 50, 100));
    vision.setPosition(position.getX() - fov + 10, position.getY() - fov + 10);
    window->draw(vision);
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

void Boid::align (vector<Boid> neighbours) {
    PVector steerDirection;
    
    for (Boid & boid : neighbours) {
        steerDirection.add(boid.velocity);
    }
    
    if (neighbours.size() > 0) {
        steerDirection.divScalar(neighbours.size());
        steerDirection.setMagnitude(max_speed);
        steerDirection.sub(this->velocity);
        steerDirection.limit(max_force);

        this->acceleration.add(steerDirection);
    }
}

void Boid::cohesion (vector<Boid> neighbours) {
    PVector steerPosition;
    
    for (Boid & boid : neighbours) {
        steerPosition.add(boid.position);
    }
    
    if (neighbours.size() > 0) {
        steerPosition.divScalar(neighbours.size());
        steerPosition.sub(this->position);
        steerPosition.setMagnitude(max_speed);
        steerPosition.sub(this->velocity);
        steerPosition.limit(max_force);

        this->acceleration.add(steerPosition);
    }
}