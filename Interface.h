#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cell.h"
#include "Rules.h"
#include "Grid.h"
#include <vector>
#include <string>

class Interface {
protected:
    int generations;
    int mode;
public:
    void redirectMode(Grid &g);
    Interface();
    void displayTerminal(Grid &g) const;
    void displaySFML(Grid &g) const;
    int getGenerations() const;
    int getMode() const;
    void setGenerations(int gen);
    void setMode(int m);
    void typeGenerations();
    void typeMode();
};

#endif // INTERFACE_H
