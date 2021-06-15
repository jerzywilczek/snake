//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_GLOBALS_H
#define SNAKE_GLOBALS_H


#include <SFML/Graphics/Color.hpp>

const int FIELD_WIDTH = 8;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 400;
const sf::Time MIN_STEP_TIME = sf::seconds(1.f / 40.f);
const sf::Time MAX_STEP_TIME =  sf::seconds(1.f / 4.f);
const sf::Color MAIN_COLOR(255, 255, 255);
const sf::Color BACKGROUND_COLOR(0, 0, 0);

#endif //SNAKE_GLOBALS_H
