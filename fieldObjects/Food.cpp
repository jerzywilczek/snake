//
// Created by jerzy on 6/14/21.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "Food.h"
#include "../globals.h"

Food::Food(float x, float y) {
    sprite = sf::RectangleShape(sf::Vector2f(FIELD_WIDTH, FIELD_WIDTH));
    sprite.setPosition(x, y);
    sprite.setFillColor(MAIN_COLOR);
    sprite.setOutlineColor(BACKGROUND_COLOR);
    sprite.setOutlineThickness((double) -FIELD_WIDTH / 2);
}
