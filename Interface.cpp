#include "Interface.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <chrono>


Interface::Interface() : mode(0), generations(10), delay(500) {}

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
void Interface::setDelay(int d) {
    delay = d;
}
void Interface::typeGenerations() {
    std::cout<<"\nType the number of generations wanted: ";
    std::cin>>generations;
}
void Interface::typeMode() {
    std::cout<<"\nType the display number wanted, 0 for terminal, 1 for SFML: ";
    std::cin >> mode;
}
void Interface::typeDelay() {
    std::cout<<"\nType the delay between 2 iterations (in milliseconds): ";
    std::cin >> delay;
}

void Interface::redirectMode(Grid &g, Save &s) {
    if (mode == 0) {displayTerminal(g, s);}
    if (mode == 1) {displaySFML(g, s);}
}

void Interface::displayTerminal(Grid &g, Save &s) const {
    // Check the grid's size
    int rows = g.getRows();
    int cols = g.getCols();
    std::cout << "Grid's size :  " << rows << "x" << cols << "\n";

    for (int i=0; i<generations; i++) {
    // Parcours de la grille
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Get cell's state and display it
            bool state = g.getGrid(i, j).getState();
            std::cout << (state ? "1" : "0") << " ";
        }
        std::cout << "\n"; // Fin de ligne pour chaque ligne de la grille
    }
        std::cout << "\n"; // Ligne vide après avoir affiché la grille
        s.saveFile(g,i+1);
        g.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
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

    // Draw the cells
    for (int i = 0; i < g.getRows(); ++i) {
        for (int j = 0; j < g.getCols(); ++j) {
            sf::RectangleShape cellShape(sf::Vector2f(g.getCellSize() - 1, g.getCellSize() - 1));
            cellShape.setPosition(j * g.getCellSize(), i * g.getCellSize());

            // Appliquer une couleur spéciale pour les obstacles
            if (g.getGrid(i, j).getIsObstacle()) {
                cellShape.setFillColor(g.getGrid(i, j).getState() ? sf::Color(150, 150, 150) : sf::Color(100, 100, 100));
            } else {
                cellShape.setFillColor(g.getGrid(i, j).getState() ? sf::Color(2, 58, 102) : sf::Color(255, 249, 177));
            }
            window.draw(cellShape);
        }
    }
    it += 1;
    window.display();
    g.update();
    sf::sleep(sf::milliseconds(delay));
    }
}
