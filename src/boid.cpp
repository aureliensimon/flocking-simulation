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
    separation(neighbours);
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
    PVector perceivedVelocity;
    
    for (Boid & boid : neighbours) {
        perceivedVelocity.add(boid.velocity);
    }
    
    if (neighbours.size() > 0) {
        perceivedVelocity.divScalar(neighbours.size());
        perceivedVelocity.setMagnitude(max_speed);
        perceivedVelocity.sub(this->velocity);
        perceivedVelocity.limit(max_force);
    }

    this->acceleration.add(perceivedVelocity);
}

void Boid::cohesion (vector<Boid> neighbours) {
    PVector perceivedCentre;
    
    for (Boid & boid : neighbours) {
        perceivedCentre.add(boid.position);
    }
    
    if (neighbours.size() > 0) {
        perceivedCentre.divScalar(neighbours.size());
        perceivedCentre.sub(this->position);
        perceivedCentre.setMagnitude(max_speed);
        perceivedCentre.sub(this->velocity);
        perceivedCentre.limit(max_force);
    }

    this->acceleration.add(perceivedCentre);
}

void Boid::separation (vector<Boid> neighbours) {
    PVector perceivedDistance;
    
    for (Boid & boid : neighbours) {
        PVector distanceDifference = PVector::diff(this->position, boid.position);
        distanceDifference.divScalar(pow(this->position.dist(boid.position), 2));
        perceivedDistance.add(distanceDifference);
    }

    if (neighbours.size() > 0) {
        perceivedDistance.divScalar(neighbours.size());
        perceivedDistance.setMagnitude(max_speed);
        perceivedDistance.sub(this->velocity);
        perceivedDistance.limit(max_force);
    }

    this->acceleration.add(perceivedDistance);
}