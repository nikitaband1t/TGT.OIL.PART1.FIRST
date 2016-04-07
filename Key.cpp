//
// Created by bandit on 4/7/16.
//

#include "Key.h"

Key Key::Key(int _x, int _y) {
    x = _x;
    y = _y;
}

int Key::getX() {
    return x;
}

int Key::getY() {
    return y;
}

bool Key::operator==(const Key &key) const {
    return x == key.x
           && y == key.y;
}