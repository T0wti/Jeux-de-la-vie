#include "Save.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void Save::setFilePath(std::string& filename) {
    filePath = filename;
}
void Save::typeFilePath() {
    std::cout << "\nEntrez le chemin complet du fichier : ";
    std::cin >> filePath;
}
void Save::initializeFromFile(Grid &g) {
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + filePath);
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
            //throw std::runtime_error("Grille non rectangulaire dans le fichier : " + filePath);
        //}


    // Mettre à jour les dimensions et la grille
    g.setRows(newGrid.size());
    g.setCols(colsInFile);
    g.setTotalGrid(newGrid);
}

