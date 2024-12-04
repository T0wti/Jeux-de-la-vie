#include "Save.h"
#include <fstream>
#include <stdexcept>

void Save::loadFromFile(const std::string& filename, std::vector<std::vector<Cell>>& grid, int& rows, int& cols) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + filename);
    }

    std::vector<std::vector<Cell>> newGrid;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::vector<Cell> row;
        for (char ch : line) {
            if (ch == '0') {
                row.emplace_back(Cell(false)); // Cellule morte
            } else if (ch == '1') {
                row.emplace_back(Cell(true)); // Cellule vivante
            }
        }
        if (!row.empty()) {
            newGrid.push_back(row);
        }
    }

    // Valider que la grille est rectangulaire
    size_t colsInFile = newGrid[0].size();
    //for (const auto& row : newGrid) {
        //if (row.size() != colsInFile) {
            //throw std::runtime_error("Grille non rectangulaire dans le fichier : " + filename);
        //}


    // Mettre à jour les dimensions et la grille
    rows = newGrid.size();
    cols = colsInFile;
    grid = std::move(newGrid);
}

