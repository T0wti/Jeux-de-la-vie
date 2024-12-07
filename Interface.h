#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cell.h"
#include "Rules.h"
#include "Grid.h"
#include "Save.h"
#include <vector>
#include <string>

class Interface {
protected:
    int generations;
    int mode;
    int delay;
public:
    void redirectMode(Grid &g, Save &s);
    Interface();
    void displayTerminal(Grid &g, Save &s) const;
    void displaySFML(Grid &g, Save &s) const;
    int getGenerations() const;
    int getMode() const;
    //Fonction pour set les valeurs des ints si jamais on les a déjà quelque part
    void setGenerations(int gen);
    void setMode(int m);
    void setDelay(int d);
    //Fonction pour écrire les valeurs des ints
    void typeGenerations();
    void typeMode();
    void typeDelay();
};

#endif // INTERFACE_H
