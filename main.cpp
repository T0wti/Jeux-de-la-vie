#include <iostream>
#include "Grid.h"
#include "Interface.h"
#include "Save.h"

int main() {
    Interface terminal;
    Grid gameGrid(5,5); // The size will be set according to the initialization file
    Save saver;

    terminal.typeMode();
    terminal.typeGenerations();
    terminal.typeDelay();
    saver.typeFilePath(); //Function to type the initialization file path
    if (terminal.getMode()==0) {saver.typeSaveFilePath();} //Only ask the path if we are using SFML
    saver.initializeFromFile(gameGrid);
    terminal.redirectMode(gameGrid, saver);

    return 0;
}