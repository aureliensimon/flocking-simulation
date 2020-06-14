#include "../include/obstacle.h"

void Obstacle::show (sf::RenderWindow * window) {
    sf::CircleShape obstacle(this->radius);
    obstacle.setFillColor(sf::Color(255, 0, 0, 255));
    obstacle.setPosition(position.getX(), position.getY());
    window->draw(obstacle);
}