#ifndef SAVE_H
#define SAVE_H

#include "Cell.h"
#include "Grid.h"
#include <vector>
#include <string>

class Save {
    protected:
    std::string filePath;
    std::string saveFilePath;
    std::string directoryPath;

public:
    std::string getFilePath();
    void setSaveFilePath(std::string& filename);
    void typeSaveFilePath();
    void setFilePath(std::string& filename);
    void typeFilePath();
    // Function to load a grid from a file
    void initializeFromFile(Grid &g);
    void saveFile(Grid &g, int gen);
};

#endif // SAVE_H