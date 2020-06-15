#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "../include/flock.h"
#include "../include/obstacle.h"

#define WIDTH 800
#define HEIGHT 800
#define SIZE 10

using namespace std;

int main() {

    srand (time(NULL));

    vector<Obstacle> obstacles;
    Flock f = Flock(1);
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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) f.addBoid(sf::Mouse::getPosition(window));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) obstacles.push_back(Obstacle(sf::Mouse::getPosition(window)));

        window.clear();

        for (Obstacle & o : obstacles) {
            o.show(&window);
        }

        f.update(obstacles);
        f.show(&window);
        window.display();
    }

    return 0;
}