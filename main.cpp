#include <iostream>
#include "Grid.h"
#include "Interface.h"

int main() {
    try {
        Interface terminal;
        terminal.typeMode();
        terminal.typeGenerations();
        std::string filePath;
        std::cout << "\nEntrez le chemin complet du fichier : ";
        std::cin >> filePath;

        Grid gameGrid(5,5); // La taille sera déterminée par le fichier
        gameGrid.loadFromFile(filePath);
        terminal.redirectMode(gameGrid);

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }

    return 0;
}

