//
// Created by jerzy on 6/14/21.
//

#include "GameDrawer.h"

void GameDrawer::update() {
    area.update();
    for (auto field : area.forUpdate()) {
        sf::RectangleShape shape;
        switch (field->getFieldType()) {
            case Field::FieldType::EMPTY:
                shape = empty;
                break;
            case Field::FieldType::WALL:
                shape = wall;
                break;
            case Field::FieldType::SNAKE:
                shape = snake;
                break;
            case Field::FieldType::FOOD:
                shape = food;
                break;
        }
        shape.setPosition((float) field->getX() * (float) fieldLen, (float) field->getY() * (float) fieldLen);
        window->draw(shape);
    }
    area.clearUpdates();
    window->display();
}

GameDrawer::GameDrawer(sf::RenderWindow *window, int width, int height, int fieldLen, const sf::Color &backgroundColor,
                       const sf::Color &wallColor, const sf::Color &snakeColor, const sf::Color &foodColor) :
        width{width},
        height{height},
        fieldLen{fieldLen},
        window{window},
        area{width / fieldLen, height / fieldLen},
        empty{sf::Vector2f((float) fieldLen, (float) fieldLen)},
        wall{sf::Vector2f((float) fieldLen, (float) fieldLen)},
        snake{sf::Vector2f((float) fieldLen, (float) fieldLen)},
        food{sf::Vector2f((float) fieldLen, (float) fieldLen)} {
    empty.setFillColor(backgroundColor);

    wall.setFillColor(wallColor);

    snake.setFillColor(snakeColor);

    float foodOutline = (float) fieldLen / 4;
    food.setFillColor(foodColor);
    food.setOutlineColor(backgroundColor);
    food.setOutlineThickness(-foodOutline);
}
