#include <iostream>
#include "Grid.h"
#include "Interface.h"

int main() {
    try {
        std::string filePath;
        std::cout << "Entrez le chemin complet du fichier : ";
        std::cin >> filePath;

        Grid gameGrid(5,5); // La taille sera déterminée par le fichier
        Interface terminal;
        gameGrid.loadFromFile(filePath);

        std::cout << "Grille initiale :\n";
        terminal.display(gameGrid);

        for (int i = 0; i < 10; ++i) {
            std::cout << "Generation " << i + 1 << ":\n";
            gameGrid.update();
            terminal.display(gameGrid);
        }

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }

    return 0;
}

