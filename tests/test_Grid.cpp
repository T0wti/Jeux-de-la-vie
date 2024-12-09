#include "gtest/gtest.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../Rules.h"

// Check the default builder
TEST(GridTest, DefaultConstructor) {
    Grid grid;

    EXPECT_EQ(grid.getRows(), 1);
    EXPECT_EQ(grid.getCols(), 1);
}

// Check the builder with settings
TEST(GridTest, ParameterizedConstructor) {
    Grid grid(5, 5);

    EXPECT_EQ(grid.getRows(), 5);
    EXPECT_EQ(grid.getCols(), 5);
}

// Check if we can get and set the size correctly
TEST(GridTest, SetGetRowsCols) {
    Grid grid(5, 5);

    grid.setRows(10);
    grid.setCols(10);

    EXPECT_EQ(grid.getRows(), 10);
    EXPECT_EQ(grid.getCols(), 10);
}

// Check CountAliveNeighbors
TEST(GridTest, CountAliveNeighbors) {
    Grid grid(3, 3);

    // We make cell with different states
    Cell aliveCell(true);  // Alive cell
    Cell deadCell(false);  // Dead cell

    // Fill a grid with the cells
    grid.setTotalGrid({
        {aliveCell, deadCell, aliveCell},
        {deadCell, aliveCell, deadCell},
        {aliveCell, deadCell, aliveCell}
    });

    // Check the aliveNeighbors for the cell (1,1)
    int aliveNeighbors = grid.countAliveNeighbors(1, 1);
    EXPECT_EQ(aliveNeighbors, 4);  // (0,0), (0,2), (2,0), (2,2) are alive
}

// Check update()
TEST(GridTest, UpdateGrid) {
    Grid grid(3, 3);
    Cell aliveCell(true);  // Cellule vivante
    Cell deadCell(false);  // Cellule morte

    // Fill the grid with cells
    grid.setTotalGrid({
        {aliveCell, deadCell, aliveCell},
        {deadCell, aliveCell, deadCell},
        {aliveCell, deadCell, aliveCell}
    });

    // Update the grid
    grid.update();

    // Check the size of the grid after the update
    const auto& updatedGrid = grid.getTotalGrid();

    // Check if the cells updated correctly
    EXPECT_EQ(updatedGrid[0][0].getState(), false);  // The cell should be dead
    EXPECT_EQ(updatedGrid[1][1].getState(), false);   // The cell should be dead too
}

// Check the obstacles
TEST(GridTest, ObstacleUpdate) {
    Grid grid(3, 3);
    Cell aliveCell(true);
    Cell deadCell(false);
    Cell obstacleCell(false, true);  // Obstacle cell

    // Fill the grid with cells (some are obstacles)
    grid.setTotalGrid({
        {aliveCell, deadCell, obstacleCell},
        {deadCell, aliveCell, obstacleCell},
        {aliveCell, deadCell, obstacleCell}
    });

    // Update the new grid
    grid.update();

    // Check the grid state after the update
    const auto& updatedGrid = grid.getTotalGrid();

    // The obstacles shouldn't change after an update
    EXPECT_EQ(updatedGrid[0][2].getIsObstacle(), true);
    EXPECT_EQ(updatedGrid[0][2].getState(), false); // Still dead
}
