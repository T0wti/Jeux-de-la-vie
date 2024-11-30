#include "bibli.h"

//Function to set a Cell in alive state
void Cell::setAlive(bool state) { alive = state; }

//Function to update a Cell state
void Cell::update(int neighbors) { alive = alive ? (neighbors == 2 || neighbors == 3) : (neighbors == 3); }

