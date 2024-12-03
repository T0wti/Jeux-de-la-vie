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
    int m;
public:
    void redirectMode(Grid &g);
    Interface(int mode, int generations);
    void displayTerminal(Grid &g) const;
    void displaySFML(Grid &g) const;

};

#endif // INTERFACE_H
