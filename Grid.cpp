#include "bibli.h"

//Fonction pour compter le nombre de cellule voisine vivante
int Grid::countAliveNeighbors(int x, int y) const {
        int count = 0;
        for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j)
                if (i || j)
                    count += (x + i >= 0 && x + i < rows && y + j >= 0 && y + j < cols && grid[x + i][y + j].isAlive());
        return count; 
}
//Builder par défaut
Grid::Grid(int r, int c) : rows(r), cols(c), grid(r, std::vector<Cell>(c)), nextGrid(r, std::vector<Cell>(c)) {}

//Fonction pour charger une matrice présente dans un fichier
void Grid::loadFromFile(const std::string& file) {
    std::ifstream f(file);
    if (!f.is_open()) throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier");
    for (auto& row : grid)
        for (auto& cell : row) {
            int state;
            if (!(f >> state)) throw std::runtime_error("Erreur : Format incorrect dans le fichier");
            cell.setAlive(state == 1);
        }
}

//Fonction pour mettre à jour la grille et passer à la suivante
void Grid::update() {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            nextGrid[i][j].update(countAliveNeighbors(i,j));
    grid.swap(nextGrid);
}