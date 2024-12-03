#include "Interface.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*void Interface::display(Grid &g) const {
    for (int i=0; i<g.getRows();i++) {
        for (int j=0; j<g.getCols();j++) {
            std::cout << (g.getGrid(i,j).getState() ? "1" : "0") << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}*/

void Interface::display(Grid &g) const {
    // Vérifiez la taille de la grille
    int rows = g.getRows();
    int cols = g.getCols();
    std::cout << "Grille de taille " << rows << "x" << cols << " :\n";

    // Parcours de la grille
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Récupérez l'état de la cellule et affichez-le
            bool state = g.getGrid(i, j).getState();
            std::cout << (state ? "1" : "0") << " ";
        }
        std::cout << "\n"; // Fin de ligne pour chaque ligne de la grille
    }
    std::cout << "\n"; // Ligne vide après avoir affiché la grille
}