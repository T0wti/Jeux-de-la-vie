#include "bibli.h"

//Constructeur par défaut
Display::Display(int r, int c, int size, int gen, int delay) : grid(r, c), cellSize(size), generations(gen), delayMs(delay) {}

//Fonction pour afficher la première grille
void Display::initialize(const std::string& file) { grid.loadFromFile(file); }

//Fonction pour lancer l'affichage
void Display::run() {
    sf::RenderWindow window(sf::VideoMode(grid.getGrid()[0].size() * cellSize, grid.getGrid().size() * cellSize),"Game of Life");
    for (int gen = 0; gen < generations && window.isOpen(); ++gen) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        window.clear();
        const auto& cells = grid.getGrid();
        for (int i = 0; i < cells.size(); ++i)
            for (int j = 0; j < cells[i].size(); ++j) {
                sf::RectangleShape cellShape(sf::Vector2f(cellSize - 1, cellSize - 1));
                cellShape.setPosition(j * cellSize, i * cellSize);
                cellShape.setFillColor(cells[i][j].isAlive() ? sf::Color::Green : sf::Color::Black);
                window.draw(cellShape);
            }
        window.display();
        grid.update();
        sf::sleep(sf::milliseconds(delayMs));
    }
}