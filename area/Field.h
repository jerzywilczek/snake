//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H


#include <optional>
#include "../fieldObjects/FieldObject.h"

class Field {
public:
    enum class FieldType{
        WALL,
        FOOD,
        SNAKE,
        EMPTY
    };

    Field(int x, int y, FieldType type = FieldType::EMPTY) : x{x}, y{y}, fieldType{type} {}

    [[nodiscard]] FieldType getFieldType() const {
        return fieldType;
    }

    [[nodiscard]] int getX() const {
        return x;
    }

    [[nodiscard]] int getY() const {
        return y;
    }

    void setFieldType(FieldType type) {
        fieldType = type;
    }

private:
    FieldType fieldType;
    int x;
    int y;

};


#endif //SNAKE_FIELD_H
