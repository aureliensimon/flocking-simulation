#include "../include/flock.h"

void Flock::settlement() {
    for (int i = 0; i < numberBoids; ++i) {
        boids.push_back(Boid(rand() % 1500, rand() % 750));
    }
}

void Flock::update() {
    for (Boid & boid : boids) {
        boid.update();
    }
}