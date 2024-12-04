#include "Save.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void Save::setFilePath(std::string& filename) {
    filePath = filename;
}
void Save::typeFilePath() {
    std::cout << "\nType the complete path to the initialization file : ";
    std::cin >> filePath;
}
void Save::setSaveFilePath(std::string& f) {
    directoryPath = f;
}
void Save::typeSaveFilePath() {
    std::cout <<"\nType the complete path to the save's folder :";
    std::cin >> directoryPath;
}
void Save::initializeFromFile(Grid &g) {
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        throw std::runtime_error("Can't open the file : " + filePath);
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

void Save::saveFile(Grid &g,int gen) {

    // Ajouter le nouveau fichier
    std::string newFileName = "/save_" + std::to_string(gen) + ".txt";

    // Retourner le nouveau chemin complet
    saveFilePath =  directoryPath + newFileName;

    std::ofstream outputFile(saveFilePath);
    if (!outputFile) {
        throw std::runtime_error("Impossible de créer ou d'ouvrir le fichier pour l'écriture : " + filePath);
    }
// Écrire les dimensions de la grille (rows et cols)
    outputFile << g.getRows() << " " << g.getCols() << "\n";
// Écriture de la matrice du jeu
    const auto& grid = g.getTotalGrid(); // Récupère la grille sous forme de std::vector<std::vector<Cell>>
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            outputFile << (cell.getState() ? '1' : '0'); // Cellule vivante -> '1', morte -> '0'
        }
        outputFile << "\n"; // Fin de la ligne
        }
    outputFile.close(); // Fermer le fichier
    if (!outputFile) {
        throw std::runtime_error("Erreur lors de l'écriture dans le fichier : " + filePath);
    }

}
