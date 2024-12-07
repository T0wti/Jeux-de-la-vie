#include "Grid.h"
#include "File_manager.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Grid::Grid() : rows(0), cols(0), cellSize(20), grid() {} // Default builder
Grid::Grid(int r, int c) : rows(r), cols(c), cellSize(20), grid(r, std::vector<Cell>(c)) {}

#include <fstream>
#include <stdexcept> 
int Grid::getRows() {
    return rows;
}
int Grid::getCols() {
    return cols;
}

void Grid::setRows(int r) {
    rows = r;
}

void Grid::setCols(int c) {
    cols = c;
}
void Grid::setTotalGrid(std::vector<std::vector<Cell>> g) {
    grid = std::move(g);
}


const Cell& Grid::getGrid(int x, int y) const {
    return grid[x][y];
}
int Grid::getCellSize() {
    return cellSize;
}
const std::vector<std::vector<Cell>> Grid::getTotalGrid() const {
    return grid;
}

int Grid::countAliveNeighbors(int x, int y) const {
    int aliveCount = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignore the cell itself

            // Coordinate calculation in toroidal mode
            int nx = (x + dx + rows) % rows; 
            int ny = (y + dy + cols) % cols; 

            // Check if the neighbor is alive
            if (grid[nx][ny].getState()) {
                ++aliveCount;
            }
        }
    }

    return aliveCount;
}

void Grid::update() {
    Rules rule;
    std::vector<std::vector<Cell>> newGrid = grid; // Copy of current grid

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Don't update obstacles
            if (grid[i][j].getIsObstacle()) {
                continue;  // If the cell is an obstacle, its update is ignored.
            }

            int aliveNeighbors = countAliveNeighbors(i, j); // Number of alive neighbors
            bool newState = rule.applyRules(grid[i][j], aliveNeighbors); // Apply the rules
            newGrid[i][j].setAlive(newState); // Update the new state in the new grid
        }
    }

    grid = std::move(newGrid); // Assign the new grid to the main grid
}
