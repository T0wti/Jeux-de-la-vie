#include "bibli.h"

class Cell {
    bool alive;

public:
    //Builder
    Cell(bool alive = false) : alive(alive) {}

    //Function to return the state of a Cell
    bool isAlive() const {return alive;}

    //Function to set a Cell in alive state
    void setAlive(bool state);

    //Function to update a Cell state
    void update(int neighbors);
};