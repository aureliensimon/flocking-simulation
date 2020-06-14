#include "../include/flock.h"

void Flock::settlement() {
    for (int i = 0; i < numberBoids; ++i) {
        boids.push_back(Boid(this, 1500/2, 750/2));
    }
}

void Flock::update() {
    for (Boid & boid : boids) {
        boid.update();
    }
}

void Flock::show (sf::RenderWindow * window) {
    for (Boid & boid : getBoids()) {
        //boid.showFov(window);
        boid.show(window);
    }
}