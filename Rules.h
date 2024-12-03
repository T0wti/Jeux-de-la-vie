#ifndef RULES_H
#define RULES_H

#include "Cell.h"

class Rules : public Cell {
public:
    Rules(bool state = false);
    bool applyRules(const Cell& cell, int aliveNeighbors);
};

#endif // RULES_H
