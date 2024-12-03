#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include "Rules.h"
#include <vector>
#include <string>

class Grid {
private:
    std::vector<std::vector<Cell>> grid;
    int rows, cols;

    int countAliveNeighbors(int x, int y) const;

public:
    Grid();
    Grid(int r, int c);
    void loadFromFile(const std::string& filename);
    void display() const;
    void update();
};

#endif // GRID_H
