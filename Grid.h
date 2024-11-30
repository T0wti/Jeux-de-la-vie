#include "bibli.h"
class Grid {

protected:

    int rows, cols;
    std::vector<std::vector<Cell>> grid, nextGrid;

    int countAliveNeighbors(int x, int y) const;
    
public:

//Constructeur par défaut
    Grid(int r, int c);

//Fonction pour charger une matrice présente dans un fichier
    void loadFromFile(const std::string& file);

//Fonction pour mettre à jour la grille et passer à la suivante
    void update();

//Prise de la grille sous forme de vecteur pour un nouveau traitement
    const std::vector<std::vector<Cell>>& getGrid() const { return grid; }
};