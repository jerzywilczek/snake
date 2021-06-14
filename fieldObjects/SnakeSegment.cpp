//
// Created by jerzy on 6/14/21.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "SnakeSegment.h"
#include "../globals.h"

SnakeSegment::SnakeSegment(float x, float y) {
    sprite = sf::RectangleShape{sf::Vector2f{FIELD_WIDTH, FIELD_WIDTH}};
    sprite.setPosition(x, y);
    sprite.setFillColor(MAIN_COLOR);
}
