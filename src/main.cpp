#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "../include/flock.h"

#define WIDTH 600
#define HEIGHT 600
#define SIZE 10

using namespace std;

int main() {

    srand (time(NULL));

    Flock f = Flock(50);
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
        f.show(&window);
        window.display();
    }

    return 0;
}