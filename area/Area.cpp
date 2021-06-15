//
// Created by jerzy on 6/14/21.
//

#include "Area.h"
#include <random>

Area::Area(int width, int height) : width{width}, height{height} {
    setGame();
    snake = std::make_unique<Snake>(width / 2, height / 2, this);

}

void Area::update() {
    snake->move();
    pickFoodField();
    if (isGameOver) {
        setGame();
        snake = std::make_unique<Snake>(width / 2, height / 2, this);
        isGameOver = false;
    }

}

void Area::setGame() {
    fields.clear();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            fields.emplace_back(j, i);
        }
    }

    for (int i = 0; i < width; ++i) {
        at(i, 0).setFieldType(Field::FieldType::WALL);
        at(i, height - 1).setFieldType(Field::FieldType::WALL);
    }

    for (int i = 1; i < height - 1; ++i) {
        at(0, i).setFieldType(Field::FieldType::WALL);
        at(width - 1, i).setFieldType(Field::FieldType::WALL);
    }
    pickFoodField();
    for (auto &field : fields) {
        queueUpdate(field);
    }
}

void Area::queueUpdate(Field &field) {
    queuedUpdates.insert(&field);
}

void Area::clearUpdates() {
    queuedUpdates.clear();
}

std::set<Field *> &Area::forUpdate() {
    return queuedUpdates;
}

Field *Area::pickFoodField() {
    if (foodField == nullptr || foodField->getFieldType() != Field::FieldType::FOOD) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, (int) fields.size() - 1);
        int pos;
        do {
            pos = dis(gen);
        } while (fields[pos].getFieldType() != Field::FieldType::EMPTY);
        fields[pos].setFieldType(Field::FieldType::FOOD);
        queueUpdate(fields[pos]);
        foodField = &fields[pos];
    }
    return foodField;
}

size_t Area::score() {
    return snake->length();
}

void Area::keyPressed(sf::Keyboard::Key key) {
    snake->updateDirection(key);
}
