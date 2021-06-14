//
// Created by jerzy on 6/14/21.
//

#include "Wall.h"

Wall::Wall(float x, float y) {
    sprite = sf::RectangleShape(sf::Vector2f(FIELD_WIDTH, FIELD_WIDTH));
    sprite.setPosition(x, y);
    sprite.setFillColor(MAIN_COLOR);
}

