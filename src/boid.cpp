#include "../include/boid.h"

void Boid::update () {
    position.add(velocity);
    velocity.add(acceleration);
}

void Boid::show (sf::RenderWindow * window) {
    sf::CircleShape shape(10, 3);
    shape.setFillColor(sf::Color(getColorR(), getColorG(), getColorB(), 255));
    shape.setPosition(position.getX(), position.getY());
    window->draw(shape);
}