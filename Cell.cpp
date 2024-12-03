#include "Cell.h"

Cell::Cell(bool state) : isAlive(state) {}

void Cell::setAlive(bool state) {
    isAlive = state;
}

bool Cell::getState() const {
    return isAlive;
}
