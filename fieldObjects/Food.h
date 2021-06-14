//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H


#include "FieldObject.h"

class Food : public FieldObject {
public:
    Food(float x, float y);

    const sf::Shape &getSprite() const override { return sprite; }

    OnEaten onEaten() const override { return OnEaten::GROW; }

private:
    sf::RectangleShape sprite;
};


#endif //SNAKE_FOOD_H
