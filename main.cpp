#include "bibli.h"

int main() {
    try {
        int rows = 20, cols = 20, cellSize = 20, generations = 100, delayMs = 200;
        std::cout << "Entrez le chemin vers le fichier d'initialisation : ";
        std::string filename;
        std::cin >> filename;

        Display game(rows, cols, cellSize, generations, delayMs);
        game.initialize(filename);
        game.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}