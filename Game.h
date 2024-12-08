#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cell.h"
#include "Rules.h"
#include "Grid.h"
#include "File_manager.h"
#include <vector>
#include <string>

class Game {
protected:
    int generations;
    int mode;
    int delay;
public:
    void redirectMode(Grid &g, File_manager &s);
    Game();
    void displayTerminal(Grid &g, File_manager &s) const;
    void displaySFML(Grid &g, File_manager &s) const;
    int getGenerations() const;
    int getMode() const;
    int getDelay() const;
//Function to set int values if you already have them somewhere
    void setGenerations(int gen);
    void setMode(int m);
    void setDelay(int d);
    //Function to type the int values
    void typeGenerations();
    void typeMode();
    void typeDelay();
};

#endif // INTERFACE_H
