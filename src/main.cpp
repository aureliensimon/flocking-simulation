#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/boid.h"

#define WIDTH 1500
#define HEIGHT 750

using namespace std;

int main() {

    Boid b = Boid(WIDTH / 2, HEIGHT / 2);
    cout << b.getPositionX() << endl;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Boids");
    window.setFramerateLimit(60);

    sf::CircleShape shape(5);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        b.update();
        shape.setPosition(b.getPositionX(), b.getPositionY());
        window.draw(shape);
        window.display();
    }

    return 0;
}