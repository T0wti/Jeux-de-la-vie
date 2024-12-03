#include <iostream>
#include "Grid.h"
#include "Interface.h"

int main() {
    try {
        int m;
        std::cout<< "\nTaper le numéro d'affichage voulu, 0 pour terminal, 1 pour SFML : ";
        std::cin >> m;
        std::string filePath;
        std::cout << "\nEntrez le chemin complet du fichier : ";
        std::cin >> filePath;

        Grid gameGrid(5,5); // La taille sera déterminée par le fichier
        Interface terminal(m);
        gameGrid.loadFromFile(filePath);
        
        for (int i = 0; i < 10; ++i) {
            gameGrid.update();
            terminal.display(gameGrid);
        }

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }

    return 0;
}

