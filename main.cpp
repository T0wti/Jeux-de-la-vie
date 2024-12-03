#include <iostream>
#include "Grid.h"

int main() {
    try {
        std::string filePath;
        std::cout << "Entrez le chemin complet du fichier : ";
        std::cin >> filePath;

        Grid gameGrid; // La taille sera déterminée par le fichier
        gameGrid.loadFromFile(filePath);

        std::cout << "Grille initiale :\n";
        gameGrid.display();

        for (int i = 0; i < 10; ++i) {
            std::cout << "Generation " << i + 1 << ":\n";
            gameGrid.update();
            gameGrid.display();
        }

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }

    return 0;
}

