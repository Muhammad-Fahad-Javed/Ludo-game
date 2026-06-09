#include"safeCell.h"

bool SafeCell :: isSafe() {
    return true;
}

bool SafeCell::operator == (Cell& C) {
    if (this->x == C.x && this->y == C.y) {
        return true;
    }
    return false;
}