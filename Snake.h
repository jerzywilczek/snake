//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H


#include <list>
#include "area/Area.h"

class Area;

class Snake {
public:
    enum class Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    Snake(int startX, int startY, Area *area);

    void move();

    size_t length() { return body.size(); }

    void updateDirection(const sf::Keyboard::Key keyPressed);

private:
    Area *area;
    std::list<Field *> body;
    Direction movingDirection;
};


#endif //SNAKE_SNAKE_H
