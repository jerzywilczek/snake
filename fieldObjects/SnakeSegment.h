//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_SNAKESEGMENT_H
#define SNAKE_SNAKESEGMENT_H


#include "FieldObject.h"

class SnakeSegment : public FieldObject {
public:
    SnakeSegment(float x, float y);

    const sf::Shape &getSprite() const override { return sprite; }

    OnEaten onEaten() const override { return OnEaten::DIE; }

private:
    sf::RectangleShape sprite;
};


#endif //SNAKE_SNAKESEGMENT_H
