//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H


#include <optional>

class Field {
public:
    enum class FieldType{
        WALL,
        FOOD,
        SNAKE,
        EMPTY
    };

    Field(int x, int y, FieldType type = FieldType::EMPTY) : x{x}, y{y}, fieldType{type} {}

    [[nodiscard]] FieldType getFieldType() const;

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getY() const;

    void setFieldType(FieldType type);

private:
    FieldType fieldType;
    int x;
    int y;

};


#endif //SNAKE_FIELD_H
