//
// Created by jerzy on 6/14/21.
//

#include "Area.h"

Area::Area(int width, int height) : width{width}, height{height}, fields() {
    for(int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j) {
            fields.emplace_back(i, j);
        }
    }
}
