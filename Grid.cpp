#include "Grid.h"
#include "Save.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Grid::Grid() : rows(0), cols(0), cellSize(20), grid() {} // Constructeur par défaut
Grid::Grid(int r, int c) : rows(r), cols(c), cellSize(20), grid(r, std::vector<Cell>(c)) {}

#include <fstream>
#include <stdexcept> // Pour gérer les exceptions

int Grid::getRows() {
    return rows;
}
int Grid::getCols() {
    return cols;
}

void Grid::setRows(int r) {
    rows = r;
}

void Grid::setCols(int c) {
    cols = c;
}
void Grid::setTotalGrid(std::vector<std::vector<Cell>> g) {
    grid = std::move(g);
}


const Cell& Grid::getGrid(int x, int y) const {
    return grid[x][y];
}
int Grid::getCellSize() {
    return cellSize;
}
const std::vector<std::vector<Cell>> Grid::getTotalGrid() const {
    return grid;
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

