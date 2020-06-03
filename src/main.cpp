#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "../include/flock.h"
#include "../include/boid.h"

#define WIDTH 1500
#define HEIGHT 750
#define SIZE 10

using namespace std;

int main() {

    Flock f = Flock(40);
    f.settlement();

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Boids", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        f.update();
        for (Boid & boid : f.getBoids()) {
            sf::CircleShape shape(SIZE, 3);
            shape.setFillColor(sf::Color(boid.getColorR(), boid.getColorG(), boid.getColorB(), 255));
            shape.setPosition(boid.getPositionX(), boid.getPositionY());
            window.draw(shape);
        }
        window.display();
    }

    return 0;
}