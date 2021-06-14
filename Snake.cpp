//
// Created by jerzy on 6/14/21.
//

#include <SFML/Window/Keyboard.hpp>
#include "Snake.h"

void Snake::updateDirection() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && movingDirection != Direction::DOWN) {
        movingDirection = Direction::UP;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && movingDirection != Direction::LEFT) {
        movingDirection = Direction::RIGHT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && movingDirection != Direction::UP) {
        movingDirection = Direction::DOWN;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && movingDirection != Direction::RIGHT) {
        movingDirection = Direction::LEFT;
    }
}

void Snake::move() {
    updateDirection();
    Field *head = body.front();
    Field *nextHeadPosition;
    int nextX = head->getX();
    int nextY = head->getY();
    switch (movingDirection) {
        case Direction::UP:
            nextY--;
            break;
        case Direction::RIGHT:
            nextX++;
            break;
        case Direction::DOWN:
            nextY++;
            break;
        case Direction::LEFT:
            nextX--;
            break;
    }
    nextHeadPosition = &area->at(nextX, nextY);
    bool grow = false;
    switch (nextHeadPosition->getFieldType()) {
        case Field::FieldType::WALL:
        case Field::FieldType::SNAKE:
            area->gameOver();
            break;
        case Field::FieldType::FOOD:
            grow = true;
            break;
        case Field::FieldType::EMPTY:
            break;
    }
    body.push_front(nextHeadPosition);
    nextHeadPosition->setFieldType(Field::FieldType::SNAKE);
    area->queueUpdate(*nextHeadPosition);
    if (!grow) {
        body.back()->setFieldType(Field::FieldType::EMPTY);
        area->queueUpdate(*body.back());
        body.pop_back();
    }
}

Snake::Snake(int startX, int startY, Area *area) : area{area}, body(), movingDirection{Direction::UP} {
    area->at(startX, startY).setFieldType(Field::FieldType::SNAKE);
    area->at(startX, startY + 1).setFieldType(Field::FieldType::SNAKE);
    body.push_back(&area->at(startX, startY));
    body.push_back(&area->at(startX, startY + 1));

}
