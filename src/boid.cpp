#include "../include/boid.h"

void Boid::update() {
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;

    this->velocity.x += this->acceleration.x;
    this->velocity.y += this->acceleration.y;
}