#include <iostream>
#include "Grid.h"
#include "Interface.h"

int main() {
    try {
        int m, gen;
        std::cout<< "\nTaper le numéro d'affichage voulu, 0 pour terminal, 1 pour SFML : ";
        std::cin >> m;
        std::cout<<"\nEntrer le nombre de générations voulu : ";
        std::cin >> gen;
        std::string filePath;
        std::cout << "\nEntrez le chemin complet du fichier : ";
        std::cin >> filePath;

        Grid gameGrid(5,5); // La taille sera déterminée par le fichier
        Interface terminal(m,gen);
        gameGrid.loadFromFile(filePath);
        terminal.redirectMode(gameGrid);

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }

    return 0;
}

