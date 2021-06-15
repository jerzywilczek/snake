//
// Created by jerzy on 6/14/21.
//

#include <SFML/Window/Keyboard.hpp>
#include "Snake.h"

void Snake::updateDirection(const sf::Keyboard::Key keyPressed) {
    if (keyPressed == sf::Keyboard::W && previousMovingDirection != Direction::DOWN) {
        movingDirection = Direction::UP;
    } else if (keyPressed == sf::Keyboard::D && previousMovingDirection != Direction::LEFT) {
        movingDirection = Direction::RIGHT;
    } else if (keyPressed == sf::Keyboard::S && previousMovingDirection != Direction::UP) {
        movingDirection = Direction::DOWN;
    } else if (keyPressed == sf::Keyboard::A && previousMovingDirection != Direction::RIGHT) {
        movingDirection = Direction::LEFT;
    }
}

void Snake::move() {
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
    previousMovingDirection = movingDirection;
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

Snake::Snake(int startX, int startY, Area *area) : area{area} {
    area->at(startX, startY).setFieldType(Field::FieldType::SNAKE);
    area->at(startX, startY + 1).setFieldType(Field::FieldType::SNAKE);
    body.push_back(&area->at(startX, startY));
    body.push_back(&area->at(startX, startY + 1));

}
