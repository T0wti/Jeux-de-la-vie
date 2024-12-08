#include "gtest/gtest.h"
#include "../File_manager.h"
#include <fstream>
#include <stdexcept>
#include <sstream>

// Test the File_manager::initializeFromFile function
TEST(FileManagerTest, InitializeFromFileTest) {
    // Create a temporary grid
    Grid grid;

    // Create a File_manager object
    File_manager fileManager;

    // Set the file path to a test file
    std::string testFilePath = "../test_input.txt";
    fileManager.setFilePath(testFilePath);

    // Create the test file content
    std::ofstream testFile(testFilePath);
    testFile << "3 3\n"; // Grid dimensions (rows x cols)
    testFile << "111\n";
    testFile << "101\n";
    testFile << "111\n";  // Grid data (1 for alive, 0 for dead, no obstacles here)
    testFile.close();

    // Initialize the grid from the file
    fileManager.initializeFromFile(grid);

    // Verify that the grid's dimensions are correct
    EXPECT_EQ(grid.getRows(), 3);
    EXPECT_EQ(grid.getCols(), 3);

    // Verify the cell states (expecting all cells to be alive except for the middle one)
    const auto& gridData = grid.getTotalGrid();
    EXPECT_TRUE(gridData[0][0].getState());  // Alive
    EXPECT_TRUE(gridData[0][1].getState());  // Alive
    EXPECT_TRUE(gridData[0][2].getState());  // Alive
    EXPECT_TRUE(gridData[1][0].getState());  // Alive
    EXPECT_FALSE(gridData[1][1].getState()); // Dead
    EXPECT_TRUE(gridData[1][2].getState());  // Alive
    EXPECT_TRUE(gridData[2][0].getState());  // Alive
    EXPECT_TRUE(gridData[2][1].getState());  // Alive
    EXPECT_TRUE(gridData[2][2].getState());  // Alive

    // Clean up the temporary file
    std::remove(testFilePath.c_str());
}

// Test the File_manager::saveFile function
TEST(FileManagerTest, SaveFileTest) {
    // Create a temporary grid with predefined values
    Grid grid;
    grid.setRows(3);
    grid.setCols(3);

    std::vector<std::vector<Cell>> gridData = {
        {Cell(true), Cell(true), Cell(true)},
        {Cell(true), Cell(false), Cell(true)},
        {Cell(true), Cell(true), Cell(true)}
    };

    grid.setTotalGrid(gridData);

    // Create a File_manager object
    File_manager fileManager;

    // Set the directory path where the file will be saved
    std::string directoryPath = "C:/Users/diego/CLionProjects/Jeux-de-la-vie/tests/test_save";  // Save in the current directory
    fileManager.setSaveFilePath(directoryPath);

    // Save the grid to a file
    fileManager.saveFile(grid, 1);  // Assuming generation 1 for the filename

    // Verify that the file is created
    std::string expectedFilePath = directoryPath + "/save_1.txt";
    std::ifstream savedFile(expectedFilePath);
    ASSERT_TRUE(savedFile.is_open());  // Check if file was created

    // Read the file content to verify it was written correctly
    std::string line;
    std::getline(savedFile, line);
    EXPECT_EQ(line, "3 3");  // The first line should be the dimensions

    // Check the grid content (expecting 1 for alive, 0 for dead)
    std::getline(savedFile, line);
    EXPECT_EQ(line, "111");

    std::getline(savedFile, line);
    EXPECT_EQ(line, "101");

    std::getline(savedFile, line);
    EXPECT_EQ(line, "111");

    savedFile.close();

    // Clean up the saved file
    std::remove(expectedFilePath.c_str());
}
