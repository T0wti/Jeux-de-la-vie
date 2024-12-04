#ifndef SAVE_H
#define SAVE_H

#include "Cell.h"
#include <vector>
#include <string>

class Save {
public:
    // Fonction pour charger une grille depuis un fichier
    void loadFromFile(const std::string& filename, std::vector<std::vector<Cell>>& grid, int& rows, int& cols);
};

#endif // SAVE_H