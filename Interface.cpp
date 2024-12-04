#include "Interface.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

Interface::Interface() : mode(0), generations(10) {}

int Interface::getGenerations() const {
    return generations;
}
int Interface::getMode() const {
    return mode;
}
void Interface::setGenerations(int gen) {
    generations = gen;
}
void Interface::setMode(int m) {
    mode = m;
}
void Interface::typeGenerations() {
    std::cout<<"\nEntrer le nombre de générations voulu : ";
    std::cin>>generations;
}
void Interface::typeMode() {
    std::cout<<"\nTaper le numéro d'affichage voulu, 0 pour terminal, 1 pour SFML : ";
    std::cin >> mode;
}

void Interface::redirectMode(Grid &g, Save &s) {
    if (mode == 0) {displayTerminal(g, s);}
    if (mode == 1) {displaySFML(g, s);}
}

void Interface::displayTerminal(Grid &g, Save &s) const {
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
    s.saveFile(g,generations);
    g.update();
    }
}

void Interface::displaySFML(Grid &g, Save &s) const {

bool isWindowOpen = false;
int it = 0;

sf::RenderWindow window; // Déclaration en dehors du bloc conditionnel


if (!isWindowOpen) {
    // Initialiser la fenêtre
    window.create(sf::VideoMode(g.getTotalGrid()[0].size() * g.getCellSize(),g.getTotalGrid().size() * g.getCellSize()), "Game of Life");
    isWindowOpen = true; // Marquer qu'une fenêtre est ouverte
}
    while (window.isOpen()&& it<generations) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

    window.clear();

    // Dessiner les cellules
    for (int i = 0; i < g.getRows(); ++i) {
        for (int j = 0; j < g.getCols(); ++j) {
            sf::RectangleShape cellShape(sf::Vector2f(g.getCellSize() - 1, g.getCellSize() - 1));
            cellShape.setPosition(j * g.getCellSize(), i * g.getCellSize());
            cellShape.setFillColor(g.getGrid(i, j).getState() ? sf::Color(2, 58, 102) : sf::Color(255, 249, 177));
            window.draw(cellShape);
        }
    }
    it += 1;
    window.display();
    s.saveFile(g,generations);
    g.update();
    sf::sleep(sf::milliseconds(500));
    }
}