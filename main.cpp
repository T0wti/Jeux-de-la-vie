#include <iostream>
#include "Grid.h"
#include "Interface.h"
#include "Save.h"

int main() {
    Interface terminal;
    Grid gameGrid(5,5); // La taille sera déterminée par le fichier
    Save saver;

    terminal.typeMode();
    terminal.typeGenerations();
    std::string filePath;
    std::cout << "\nEntrez le chemin complet du fichier : ";
    std::cin >> filePath;

    gameGrid.initializeFromFile(filePath, saver);
    terminal.redirectMode(gameGrid);

    return 0;
}

