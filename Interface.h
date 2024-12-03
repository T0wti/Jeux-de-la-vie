#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cell.h"
#include "Rules.h"
#include "Grid.h"
#include <vector>
#include <string>

class Interface {
public:
    void display(Grid &g) const;
};

#endif // INTERFACE_H
