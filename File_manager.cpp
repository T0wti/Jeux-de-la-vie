#include "File_manager.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void File_manager::setFilePath(std::string& filename) {
    filePath = filename;
}
void File_manager::typeFilePath() {
    std::cout << "\nType the complete path to the initialization file : ";
    std::cin >> filePath;
}
void File_manager::setSaveFilePath(std::string& f) {
    directoryPath = f;
}
void File_manager::typeSaveFilePath() {
    std::cout <<"\nType the complete path to the save's folder :";
    std::cin >> directoryPath;
}
void File_manager::initializeFromFile(Grid &g) {
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        throw std::runtime_error("Can't open the file : " + filePath);
    }
    int r, c;
    inputFile >> r >> c;
    g.setRows(r);
    g.setCols(c);
    // Delete the first line containing the dimensions (r and c)
    std::string line;
    std::getline(inputFile, line);  // Read a line of text from the input file and store it in the 'line' variable

    std::vector<std::vector<Cell>> newGrid;

    while (std::getline(inputFile, line)) {
        std::vector<Cell> row;
        for (char ch : line) {
            if (ch == '0') {
                row.emplace_back(Cell(false)); // Dead cell
            } else if (ch == '1') {
                row.emplace_back(Cell(true)); // Alive cell
            } else if (ch == '2') {
                row.emplace_back(Cell(false, true)); // Dead obstacle cell
            } else if (ch == '3') {
                row.emplace_back(Cell(true, true)); // Alive obstacle cell
            }
        }
        if (!row.empty()) {
            newGrid.push_back(row);
        }
    }

    // Set the new grid
    g.setTotalGrid(newGrid);
}

void File_manager::saveFile(Grid &g,int gen) {

    // Make a new save file
    std::string newFileName = "/save_" + std::to_string(gen) + ".txt";

    // Return the save's complete path
    saveFilePath =  directoryPath + newFileName;

    std::ofstream outputFile(saveFilePath);
    if (!outputFile) {
        throw std::runtime_error("Unable to create or open file for writing : " + filePath);
    }
// Write the grid dimensions (rows and cols)
    outputFile << g.getRows() << " " << g.getCols() << "\n";
// Writing game's matrix
    const auto& grid = g.getTotalGrid(); // Get the grid in a std::vector<std::vector<Cell>> form
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell.getIsObstacle()) {
                outputFile << (cell.getState() ? '3' : '2');  // If it's an obstacle, '3' for alive, '2' for dead
            } else {
                outputFile << (cell.getState() ? '1' : '0'); // If it's a cell, alive -> '1', dead -> '0
            }
        }
        outputFile << "\n"; // End of the line
        }
    outputFile.close(); // Close the file
    if (!outputFile) {
        throw std::runtime_error("Error writing to file : " + filePath);
    }

}
