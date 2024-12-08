#include "Grid.h"
#include "Game.h"
#include "File_manager.h"

int main() {
    Game G;
    Grid gameGrid(5,5); // The size will be set according to the initialization file
    File_manager saver;

    G.typeMode();
    G.typeGenerations();
    G.typeDelay();
    saver.typeFilePath(); //Function to type the initialization file path
    if (G.getMode()==0) {saver.typeSaveFilePath();} //Only ask the path if we are using the terminal
    saver.initializeFromFile(gameGrid);
    G.redirectMode(gameGrid, saver);

    return 0;
}
