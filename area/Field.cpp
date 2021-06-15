//
// Created by jerzy on 6/14/21.
//

#include "Field.h"

Field::FieldType Field::getFieldType() const {
    return fieldType;
}

int Field::getX() const {
    return x;
}

int Field::getY() const {
    return y;
}

void Field::setFieldType(Field::FieldType type) {
    fieldType = type;
}
