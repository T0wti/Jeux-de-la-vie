#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Grid::Grid() : rows(0), cols(0), grid() {} // Constructeur par défaut
Grid::Grid(int r, int c) : rows(r), cols(c), grid(r, std::vector<Cell>(c)) {}

#include <fstream>
#include <stdexcept> // Pour gérer les exceptions

void Grid::loadFromFile(const std::string& filename) {
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
    size_t cols = newGrid[0].size();
    for (const auto& row : newGrid) {
        if (row.size() != cols) {
            throw std::runtime_error("Grille non rectangulaire dans le fichier : " + filename);
        }
    }

    // Mettre à jour les dimensions et la grille
    rows = newGrid.size();
    cols = cols;
    grid = std::move(newGrid);
}


void Grid::display() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell.getState() ? "1" : "0") << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int Grid::countAliveNeighbors(int x, int y) const {
    int aliveCount = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignorer la cellule elle-même
            int nx = x + dx, ny = y + dy;
            // Vérifier si les coordonnées sont dans les limites
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny].getState()) {
                ++aliveCount;
            }
        }
    }
    return aliveCount;
}

void Grid::update() {
    Rules rule;
    std::vector<std::vector<Cell>> newGrid = grid; // Copie de la grille actuelle

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int aliveNeighbors = countAliveNeighbors(i, j); // Nombre de voisins vivants
            bool newState = rule.applyRules(grid[i][j], aliveNeighbors); // Appliquer les règles
            newGrid[i][j].setAlive(newState); // Mettre à jour l'état dans la nouvelle grille
        }
    }

    grid = std::move(newGrid); // Assigner la nouvelle grille à la grille principale
}

