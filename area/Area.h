//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_AREA_H
#define SNAKE_AREA_H


#include <vector>
#include <set>
#include <memory>
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

    std::set<Field *> &forUpdate();

    void gameOver() { isGameOver = true; }

private:
    int width;
    int height;
    std::vector<Field> fields{};
    std::unique_ptr<Snake> snake;
    std::set<Field *> queuedUpdates{};
    bool isGameOver{false};
    Field *foodField{nullptr};

    void setGame();

    Field *pickFoodField();
};


#endif //SNAKE_AREA_H
