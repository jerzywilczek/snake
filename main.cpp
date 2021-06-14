#include <SFML/Graphics.hpp>
#include "globals.h"
#include "GameDrawer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake game");
    window.setFramerateLimit(60);
    GameDrawer drawer(&window, WINDOW_WIDTH, WINDOW_HEIGHT, FIELD_WIDTH, BACKGROUND_COLOR, MAIN_COLOR, MAIN_COLOR, MAIN_COLOR);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        drawer.update();

    }

    return 0;
}