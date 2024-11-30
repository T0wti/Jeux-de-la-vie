#include "bibli.h"

class Display {
    
    protected:

    Grid grid;
    int cellSize, generations, delayMs;

public:

//Constructeur par défaut
    Display(int r, int c, int size, int gen, int delay);

//Fonction pour afficher la première grille
    void initialize(const std::string& file);

//Fonction pour lancer l'affichage
    void run();

};