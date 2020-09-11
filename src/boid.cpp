#include "../include/boid.h"

void Boid::update (vector<Obstacle> obstacles) {
    position.add(velocity);
    velocity.add(acceleration);
    velocity.limit(max_speed);
    this->acceleration.set(0, 0, 0);
    edges();

    vector<Boid> neighbours = getNeighbours();
    align(neighbours);
    separation(neighbours);
    cohesion(neighbours);
    avoidObstacle(obstacles);
}

void Boid::show (sf::RenderWindow * window) {
    double angle = (180 - atan2(velocity.getX(), velocity.getY()) * 180 / PI) * PI / 180.0;

    int smallside = 5;
    int bigside = 3*smallside;
    sf::VertexArray body(sf::Triangles, 3);

    body[0].position = sf::Vector2f(position.getX() + (-smallside)*cos(angle) - smallside*sin(angle), position.getY() + (-smallside)*sin(angle) + smallside*cos(angle));
    body[1].position = sf::Vector2f(position.getX() + smallside*cos(angle) - smallside*sin(angle), position.getY() + smallside*sin(angle) + smallside*cos(angle));
    body[2].position = sf::Vector2f(position.getX() - (-bigside)*sin(angle), position.getY() + (-bigside)*cos(angle));
    
    body[0].color = sf::Color(getColorR(), getColorG(), getColorB());
    body[1].color = sf::Color(getColorR(), getColorG(), getColorB());
    body[2].color = sf::Color(getColorR(), getColorG(), getColorB());

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
    
    perceivedVelocity.mulScalar(align_force);

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
    
    perceivedCentre.mulScalar(cohesion_force);

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

    perceivedDistance.mulScalar(separation_force);

    this->acceleration.add(perceivedDistance);
}

void Boid::avoidObstacle (vector<Obstacle> obstacles) {

    PVector perceivedDistance;
    int numberObstacles = 0;
    
    for (Obstacle obstacle : obstacles) {
        double dist = this->position.dist(obstacle.getPosition());
        
        if (dist < this->repulsion_fov) {
            PVector distanceDifference = PVector::diff(this->position, obstacle.getPosition());
            distanceDifference.divScalar(pow(this->position.dist(obstacle.getPosition()), 2));
            perceivedDistance.add(distanceDifference);
            numberObstacles++;
        }
    }

    if (numberObstacles > 0) {
        perceivedDistance.divScalar(numberObstacles);
        perceivedDistance.setMagnitude(max_speed);
        perceivedDistance.sub(this->velocity);
        perceivedDistance.limit(max_force);
    }

    perceivedDistance.mulScalar(repulsion_force);

    this->acceleration.add(perceivedDistance);
}

