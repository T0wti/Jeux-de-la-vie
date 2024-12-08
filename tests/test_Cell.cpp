#include <gtest/gtest.h>
#include "..//Cell.h"

TEST(CellTest, ConstructorInitializesStateAndObstacle) {
    // Making a cell witch is alive and not an obstacle
    Cell cell(true, false);

    // Check the initial value
    EXPECT_TRUE(cell.getState());           // The cell should be alive
    EXPECT_FALSE(cell.getIsObstacle());    // The cell should not be an obstacle
}
TEST(CellTest, SetAliveChangesStateIfNotObstacle) {
    // Making a cell witch is alive and not an obstacle
    Cell cell(true, false);

    // Edit the state of the cell
    cell.setAlive(false);

    // Check if the state changed
    EXPECT_FALSE(cell.getState());  // La cellule devrait être morte
}

TEST(CellTest, SetAliveDoesNotChangeStateIfObstacle) {
    // Making a cell witch is alive and an obstacle
    Cell cell(true, true);

    // Try to edit the living state
    cell.setAlive(false);

    // Check if the living state changed
    EXPECT_TRUE(cell.getState());  // The cell should be alive
}
TEST(CellTest, SetIsObstacleChangesObstacleState) {
    // Making a cell witch is alive and not an obstacle
    Cell cell(true, false);

    // Edit the obstacle state
    cell.setIsObstacle(true);

    // Check if the obstacle state changed
    EXPECT_TRUE(cell.getIsObstacle());  // The cell should now be an obstacle
}

TEST(CellTest, GetIsObstacleReturnsCorrectValue) {
    // Making a dead obstacle cell
    Cell cell(false, true);

    // Check if the cell is an obstacle
    EXPECT_TRUE(cell.getIsObstacle());  // The cell should be an obstacle
}
