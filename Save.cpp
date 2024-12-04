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
    int r, c;
    inputFile >> r >> c;
    g.setRows(r);
    g.setCols(c);
    // Suppression de la première ligne qui contient les dimensions (r et c)
    std::string line;
    std::getline(inputFile, line);  // Cela lit et ignore la première ligne du fichier

    std::vector<std::vector<Cell>> newGrid;

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


    // Mettre à jour la grille
    g.setTotalGrid(newGrid);
}

