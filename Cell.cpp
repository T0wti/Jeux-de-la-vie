#include "Cell.h"

Cell::Cell(bool state, bool obstacle) : isAlive(state), isObstacle(obstacle) {}

void Cell::setAlive(bool state) {
    if (!isObstacle) {
        isAlive = state;
    }

}

bool Cell::getState() const {
    return isAlive;
}

bool Cell::getIsObstacle() const {
    return isObstacle;
}

void Cell::setIsObstacle(bool state) {
    isObstacle = state;
}
