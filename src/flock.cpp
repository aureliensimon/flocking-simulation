#include "../include/flock.h"

void Flock::settlement() {
    for (int i = 0; i < numberBoids; ++i) {
        boids.push_back(Boid(this));
    }
}

void Flock::update(vector<Obstacle> obstacles) {
    for (Boid & boid : boids) {
        boid.update(obstacles);
    }
}

void Flock::show (sf::RenderWindow * window) {
    for (Boid & boid : getBoids()) {
        //boid.showFov(window);
        boid.show(window);
    }
}

void Flock::addBoid (sf::Vector2i position) {
    boids.push_back(Boid(this, position.x, position.y));
}