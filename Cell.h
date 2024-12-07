#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;
    bool isObstacle;

public:
    Cell(bool state = false, bool obstacle = false);
    void setAlive(bool state);
    bool getState() const;
    bool getIsObstacle() const;
    void setIsObstacle(bool state);
};

#endif // CELL_H
