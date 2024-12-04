#include <iostream>
#include "Grid.h"
#include "Interface.h"
#include "Save.h"

int main() {
    Interface terminal;
    Grid gameGrid(5,5); // La taille sera déterminée par le fichier
    Save saver;

    terminal.typeMode();
    terminal.typeGenerations();
    saver.typeFilePath(); //Fonction pour entrer le chemin d'accès de la grille de départ
    saver.typeSaveFilePath();

    saver.initializeFromFile(gameGrid);
    terminal.redirectMode(gameGrid, saver);

    return 0;
}

