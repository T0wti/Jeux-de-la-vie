#ifndef SAVE_H
#define SAVE_H

#include "Cell.h"
#include "Grid.h"
#include <vector>
#include <string>

class Save {
    protected:
    std::string filePath;
public:
    std::string getFilePath();
    void setFilePath(std::string& filename);
    void typeFilePath();
    // Fonction pour charger une grille depuis un fichier
    void initializeFromFile(Grid &g);
};

#endif // SAVE_H