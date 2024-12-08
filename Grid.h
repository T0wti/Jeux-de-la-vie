#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include "Rules.h"
#include <vector>
#include <string>

class Grid {
protected:
    std::vector<std::vector<Cell>> grid;
    int rows, cols, cellSize;

    //int countAliveNeighbors(int x, int y) const; -> go in public so we can do the unit test of it

public:
    int countAliveNeighbors(int x, int y) const;
    Grid();
    Grid(int r, int c);
    void setRows(int r);
    void setCols(int c);
    void setTotalGrid(std::vector<std::vector<Cell>> g);
    void update();
    int getRows();
    int getCols();
    int getCellSize();
    const Cell& getGrid(int x, int y) const;
    const std::vector<std::vector<Cell>>getTotalGrid() const;
};

#endif // GRID_H
