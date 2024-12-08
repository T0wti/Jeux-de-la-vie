#include <gtest/gtest.h>
#include "../Cell.h"

// Try the Cell's constructor
TEST(CellTest, ConstructorTest) {
    // Cell initialization with “live” state and no obstacles
    Cell cell(true, false);

    // Checking attribute values after construction
    EXPECT_TRUE(cell.getState());    // The Cell should be alive
    EXPECT_FALSE(cell.getIsObstacle()); // The cell shouldn't be an obstacle
}

// Test of setAlive
TEST(CellTest, SetAliveTest) {
    Cell cell(false, false);  // Make a non obstacle dead cell

    // The cell should be dead in first place
    EXPECT_FALSE(cell.getState());

    // Set the cell to alive state
    cell.setAlive(true);
    EXPECT_TRUE(cell.getState());  // The cell should be alive

    // Set the cell to dead state
    cell.setAlive(false);
    EXPECT_FALSE(cell.getState());  // The cell should be dead
}

// Test setAlive with an obstacle
TEST(CellTest, SetAliveWithObstacleTest) {
    Cell cell(false, true);  // The cell should be an obstacle

    //The cell should be dead and an obstacle
    EXPECT_FALSE(cell.getState());
    EXPECT_TRUE(cell.getIsObstacle());

    // We try to change the state to alive, but the cell is an obstacle
    cell.setAlive(true);
    EXPECT_FALSE(cell.getState());  // The cell should remain dead, she's an obstacle
}

// Test of getIsObstacle
TEST(CellTest, GetIsObstacleTest) {
    Cell cell(false, true);  // The cell should be dead and an obstacle

    // Check if the cell is an obstacle
    EXPECT_TRUE(cell.getIsObstacle());

    // Change the state of the obstacle
    cell.setIsObstacle(false);
    EXPECT_FALSE(cell.getIsObstacle());
}

// Test of setIsObstacle
TEST(CellTest, SetIsObstacleTest) {
    Cell cell(false, false);  // Dead cell and not an obstacle

    // The cell shouldn't be an obstacle in the first place
    EXPECT_FALSE(cell.getIsObstacle());

    // Set the cell to obstacle
    cell.setIsObstacle(true);
    EXPECT_TRUE(cell.getIsObstacle());  // The cell should now be an obstacle

    // Remove the obstacle
    cell.setIsObstacle(false);
    EXPECT_FALSE(cell.getIsObstacle());  // The cell should now not be an obstacle
}