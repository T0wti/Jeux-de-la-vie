#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;

public:
    Cell(bool state = false);
    void setAlive(bool state);
    bool getState() const;
};

#endif // CELL_H
