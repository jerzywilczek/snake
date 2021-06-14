//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_AREA_H
#define SNAKE_AREA_H


#include <vector>
#include "Field.h"

class Area {
public:
    Area(int width, int height);

    auto begin() { return fields.begin(); }
    auto end() { return fields.end(); }
    Field& at(int x, int y) {return fields[y * width + x];}

private:
    int width;
    int height;
    std::vector<Field> fields;
};


#endif //SNAKE_AREA_H
