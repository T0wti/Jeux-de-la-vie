#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Cell {
    bool alive;

public:
    Cell(bool alive = false) : alive(alive) {}
    bool isAlive() const { return alive; }
    void setAlive(bool state) { alive = state; }
    void update(int neighbors) { alive = alive ? (neighbors == 2 || neighbors == 3) : (neighbors == 3); }
};

class Grid {
    int rows, cols;
    std::vector<std::vector<Cell>> grid, nextGrid;

    int countAliveNeighbors(int x, int y) const {
        int count = 0;
        for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j)
                if (i || j)
                    count += (x + i >= 0 && x + i < rows && y + j >= 0 && y + j < cols && grid[x + i][y + j].isAlive());
        return count;
    }

public:
    Grid(int r, int c) : rows(r), cols(c), grid(r, std::vector<Cell>(c)), nextGrid(r, std::vector<Cell>(c)) {}

    void loadFromFile(const std::string& file) {
        std::ifstream f(file);
        if (!f.is_open()) throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier");
        for (auto& row : grid)
            for (auto& cell : row) {
                int state;
                if (!(f >> state)) throw std::runtime_error("Erreur : Format incorrect dans le fichier");
                cell.setAlive(state == 1);
            }
    }

    void update() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                nextGrid[i][j].update(countAliveNeighbors(i, j));
        grid.swap(nextGrid);
    }

    const std::vector<std::vector<Cell>>& getGrid() const { return grid; }
};

class Affichage {
    Grid grid;
    int cellSize, generations, delayMs;

public:
  Affichage(int r, int c, int size, int gen, int delay)
        : grid(r, c), cellSize(size), generations(gen), delayMs(delay) {}

    void initialize(const std::string& file) { grid.loadFromFile(file); }

    void run() {
        sf::RenderWindow window(sf::VideoMode(grid.getGrid()[0].size() * cellSize, grid.getGrid().size() * cellSize),
                                "Game of Life");
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
};

int main() {
    try {
        int rows = 20, cols = 20, cellSize = 20, generations = 100, delayMs = 200;
        std::cout << "Entrez le chemin vers le fichier d'initialisation : ";
        std::string filename;
        std::cin >> filename;

        Affichage game(rows, cols, cellSize, generations, delayMs);
        game.initialize(filename);
        game.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}