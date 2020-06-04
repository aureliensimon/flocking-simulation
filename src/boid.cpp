#include "../include/boid.h"

void Boid::update () {
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;

    this->velocity.x += this->acceleration.x;
    this->velocity.y += this->acceleration.y;

    edges();
}

void Boid::show (sf::RenderWindow * window) {
    sf::CircleShape shape(10, 3);
    shape.setFillColor(sf::Color(getColorR(), getColorG(), getColorB(), 255));
    shape.setPosition(getPositionX(), getPositionY());
    window->draw(shape);
}

void Boid::edges () {
    if (this->getPositionX() < 0) {
        this->position.x = 1500;
    } else if (this->getPositionX() > 1500) {
        this->position.x = 0;
    }
    if (this->getPositionY() < 0) {
        this->position.y = 750;
    } else if (this->getPositionY() > 750) {
        this->position.y = 0;
    }
}