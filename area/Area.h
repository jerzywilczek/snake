//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_AREA_H
#define SNAKE_AREA_H


#include <vector>
#include <set>
#include <memory>
#include <SFML/Window/Keyboard.hpp>
#include "Field.h"
#include "../Snake.h"


class Snake;

class Area {
public:
    Area(int width, int height);

    auto begin() { return fields.begin(); }

    auto end() { return fields.end(); }

    Field &at(int x, int y) { return fields[y * width + x]; }

    void update();

    void queueUpdate(Field &field);

    void clearUpdates();

    const std::set<std::shared_ptr<Field>> &forUpdate() const;

    void gameOver() { isGameOver = true; }

    size_t score() const;

    void keyPressed(sf::Keyboard::Key key);

private:
    int width;
    int height;
    std::vector<Field> fields{};
    std::unique_ptr<Snake> snake;
    std::set<std::shared_ptr<Field>> queuedUpdates{};
    bool isGameOver{false};
    shared_ptr<Field> foodField{nullptr};

    void setGameArea();

    shared_ptr<Field> pickFoodField();
};


#endif //SNAKE_AREA_H
