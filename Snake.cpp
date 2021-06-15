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
    std::shared_ptr<Field> head = body.front();

//    find next head position
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
    std::shared_ptr<Field> nextHeadPosition = std::shared_ptr<Field>(&area->at(nextX, nextY));

    previousMovingDirection = movingDirection;

//    check what kind of field we're stepping on and react accordingly
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

//    append new head
    body.push_front(nextHeadPosition);
    nextHeadPosition->setFieldType(Field::FieldType::SNAKE);
    area->queueUpdate(*nextHeadPosition);

//    remove tail if didn't grow
    if (!grow) {
        body.back()->setFieldType(Field::FieldType::EMPTY);
        area->queueUpdate(*body.back());
        body.pop_back();
    }
}

Snake::Snake(int startX, int startY, Area *area) : area{area} {
//    head
    area->at(startX, startY).setFieldType(Field::FieldType::SNAKE);
    body.push_back(std::shared_ptr<Field>(&area->at(startX, startY)));

//    tail
    area->at(startX, startY + 1).setFieldType(Field::FieldType::SNAKE);
    body.push_back(std::shared_ptr<Field>(&area->at(startX, startY + 1)));
}
