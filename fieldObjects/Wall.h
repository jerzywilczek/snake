//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_WALL_H
#define SNAKE_WALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "FieldObject.h"
#include "../globals.h"

class Wall : public FieldObject {
public:
    Wall(float x, float y);

    const sf::Shape &getSprite() const override { return sprite; }

    OnEaten onEaten() const override { return OnEaten::DIE; }

private:
    sf::RectangleShape sprite;
};


#endif //SNAKE_WALL_H
