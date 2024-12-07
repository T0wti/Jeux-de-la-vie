#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <chrono>


Game::Game() : mode(0), generations(10), delay(500) {}

int Game::getGenerations() const {
    return generations;
}
int Game::getMode() const {
    return mode;
}
void Game::setGenerations(int gen) {
    generations = gen;
}
void Game::setMode(int m) {
    mode = m;
}
void Game::setDelay(int d) {
    delay = d;
}
void Game::typeGenerations() {
    int tempgen;
    bool correctgen = false;
    std::cout << "\nType the number of generations wanted: ";
    while (correctgen == false) {
        // Check if the input is an integer
        if (std::cin >> tempgen) {
            // Check if the number of generations is positive
            if (tempgen > 0) {
                generations = tempgen;  // Set the number of generations
                correctgen = true;
                } else {
                std::cout << "\nInvalid number of generations, must be greater than 0. Try again: ";
            }
        } else {
            // If input is not an integer, display error message
            std::cout << "\nInvalid input for the number of generations, please enter an int: ";

            // Clear the error flag and ignore the invalid input
            std::cin.clear();  // Clears the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discards invalid input
        }
    }
}

void Game::typeMode() {
    int tempmode;
    bool correctmode = false;
    std::cout << "\nType the display number wanted, 0 for terminal, 1 for SFML: ";
    while (correctmode == false) {
        // Check if the input is an integer
        if (std::cin >> tempmode) {
            // If input is an integer, check if it's valid
            if (tempmode == 0 || tempmode == 1) {
                mode = tempmode;
                correctmode = true;  // Exit the loop
            } else {
                std::cout << "\nInvalid number, try again: ";
            }
        } else {
            // If input is not an int, display an error message
            std::cout << "\nInvalid input for the number's mode, please enter 0 or 1: ";

            // Clear the error flag and ignore the invalid input
            std::cin.clear();  // Clears the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discards invalid input
        }
    }
}
void Game::typeDelay() {
    int delaytemp;
    bool correctdelay = false;
    std::cout << "\nType the delay between 2 iterations (in milliseconds): ";

    while (correctdelay == false) {
        // Check if the input is an int
        if (std::cin >> delaytemp) {
            // Check if the delay is a positive value
            if (delaytemp > 0) {
                delay = delaytemp;  // Set the delay value
                correctdelay = true; // Input is valid, exit loop
                break;  // Break out of the loop
            } else {
                std::cout << "\nInvalid input. Delay must be greater than 0. Try again: ";
            }
        } else {
            // If the input is not an int, display an error message
            std::cout << "\nInvalid input for the delay, please enter an int: ";
            // Clear the error flag and discard invalid input
            std::cin.clear();  // Clears the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discards the invalid input
        }
    }
}

void Game::redirectMode(Grid &g, File_manager &s) {
    if (mode == 0) {displayTerminal(g, s);}
    if (mode == 1) {displaySFML(g, s);}
}

void Game::displayTerminal(Grid &g, File_manager &s) const {
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

void Game::displaySFML(Grid &g, File_manager &s) const {

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
