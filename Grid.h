#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include "Rules.h"
#include "Save.h"
#include <vector>
#include <string>

class Grid {
protected:
    std::vector<std::vector<Cell>> grid;
    int rows, cols, cellSize;

    int countAliveNeighbors(int x, int y) const;

public:
    Grid();
    Grid(int r, int c);
    void initializeFromFile(const std::string& filename, Save &s);
    void update();
    int getRows();
    int getCols();
    int getCellSize();
    const Cell& getGrid(int x, int y) const;
    const std::vector<std::vector<Cell>>getTotalGrid() const;
};

#endif // GRID_H
