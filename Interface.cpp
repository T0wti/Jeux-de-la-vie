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
    int tempgen;
    std::cout<<"\nType the number of generations wanted: ";
    std::cin>>tempgen;
    if (tempgen > 0) {
        generations = tempgen;
    } else {
        std::cout<<"\nInvalid number of generations, try again: ";
        std::cin>>tempgen;
    }
}
void Interface::typeMode() {
    int tempmode;
    bool correctmode = false;
    std::cout<<"\nType the display number wanted, 0 for terminal, 1 for SFML: ";
    std::cin>>tempmode;
    while (correctmode == false) {
        if (tempmode == 0 || tempmode == 1) {
            mode = tempmode;
            correctmode = true;
        } else {
            std::cout<<"\nInvalid number, try again: ";
            std::cin>>tempmode;
        }
    }
}
void Interface::typeDelay() {
    int delaytemp;
    bool correctdelay = false;
    std::cout<<"\nType the delay between 2 iterations (in milliseconds): ";
    std::cin >> delaytemp;
    while (correctdelay == false) {
        if (delaytemp > 0) {
            delay = delaytemp;
            correctdelay = true;
        } else {
            std::cout<<"\nInvalid input, try again: ";
            std::cin >> delaytemp;
        }
    }
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
    // Go through the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Get cell's state and display it
            bool state = g.getGrid(i, j).getState();
            std::cout << (state ? "1" : "0") << " ";
        }
        std::cout << "\n"; // End of line for each grid line
    }
        std::cout << "\n"; // Empty line after displaying the grid
        s.saveFile(g,i+1);
        g.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void Interface::displaySFML(Grid &g, Save &s) const {

bool isWindowOpen = false;
int it = 0;

sf::RenderWindow window; // Declaration outside the conditional block


if (!isWindowOpen) {
    // Init the window
    window.create(sf::VideoMode(g.getTotalGrid()[0].size() * g.getCellSize(),g.getTotalGrid().size() * g.getCellSize()), "Game of Life");
    isWindowOpen = true; // Mark window open
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

            // Apply a special color for obstacles
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
