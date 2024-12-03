#include "Interface.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

Interface::Interface(int m, int generations) : m(m), generations(generations) {}

void Interface::redirectMode(Grid &g) {
    if (m == 0) {displayTerminal(g);}
    if (m == 1) {displaySFML(g);}
}

void Interface::displayTerminal(Grid &g) const {
    // Vérifiez la taille de la grille
    int rows = g.getRows();
    int cols = g.getCols();
    std::cout << "Grille de taille " << rows << "x" << cols << " :\n";

    for (int i=0; i<generations; i++) {
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
    g.update();
    }
}

void Interface::displaySFML(Grid &g) const {

bool isWindowOpen = false;

sf::RenderWindow window; // Déclaration en dehors du bloc conditionnel


if (!isWindowOpen) {
    // Initialiser la fenêtre
    window.create(sf::VideoMode(g.getTotalGrid()[0].size() * g.getCellSize(),g.getTotalGrid().size() * g.getCellSize()), "Game of Life");
    isWindowOpen = true; // Marquer qu'une fenêtre est ouverte
}
for (int i=0; i<generations; i++) {

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

    window.clear();

    // Dessiner les cellules
    Grid g2(g);
    for (int i = 0; i < g2.getRows(); ++i) {
        for (int j = 0; j < g2.getCols(); ++j) {
            sf::RectangleShape cellShape(sf::Vector2f(g2.getCellSize() - 1, g2.getCellSize() - 1));
            cellShape.setPosition(j * g2.getCellSize(), i * g2.getCellSize());
            cellShape.setFillColor(g2.getGrid(i, j).getState() ? sf::Color::Green : sf::Color::Black);
            window.draw(cellShape);
        }
    }

    std::cout<<i;
    window.display();
    g.update();
    sf::sleep(sf::milliseconds(500));
    }
}
}