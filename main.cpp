#include <SFML/Graphics.hpp>
#include "globals.h"
#include "GameDrawer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake game");
    window.setFramerateLimit(60);

    GameDrawer drawer(&window, WINDOW_WIDTH, WINDOW_HEIGHT, FIELD_WIDTH, MIN_STEP_TIME, MAX_STEP_TIME, BACKGROUND_COLOR,
                      MAIN_COLOR,
                      MAIN_COLOR, MAIN_COLOR);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed)
                drawer.keyPressed(event.key.code);
        }

        sf::Time deltaTime = clock.restart();
        drawer.update(deltaTime);
    }

    return 0;
}