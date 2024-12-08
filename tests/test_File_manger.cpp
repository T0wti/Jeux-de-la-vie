#include <gtest/gtest.h>
#include "File_manager.h"
#include "Grid.h"
#include "Cell.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// Mock de la classe Grid
class GridMock : public Grid {
public:
    MOCK_METHOD(void, setRows, (int), (override));
    MOCK_METHOD(void, setCols, (int), (override));
    MOCK_METHOD(void, setTotalGrid, (const std::vector<std::vector<Cell>>&), (override));
    MOCK_METHOD(int, getRows, (), (const, override));
    MOCK_METHOD(int, getCols, (), (const, override));
    MOCK_METHOD(const std::vector<std::vector<Cell>>& , getTotalGrid, (), (const, override));
};

// Test de la méthode setFilePath
TEST(FileManagerTest, SetFilePath) {
    File_manager fm;
    std::string path = "/path/to/file.txt";

    fm.setFilePath(path);
    // Pas d'assertion car setFilePath n'a pas de sortie visible
    // Si une exception ou un comportement inattendu se produit, le test échoue
}

// Test de la méthode initializeFromFile avec un fichier d'exemple
TEST(FileManagerTest, InitializeFromFileValid) {
    std::string content = "3 3\n010\n101\n111\n";
    std::istringstream input(content);

    // Simuler un flux de fichier d'entrée
    std::ifstream fileMock("/path/to/valid/file.txt");
    fileMock.rdbuf(input.rdbuf()); // Attacher le flux simulé

    File_manager fm;
    GridMock grid;

    // Attendre que le fichier soit correctement lu et que les valeurs de la grille soient définies
    EXPECT_CALL(grid, setRows(3)).Times(1);
    EXPECT_CALL(grid, setCols(3)).Times(1);

    // Appeler la méthode pour initialiser la grille
    fm.initializeFromFile(grid);
}

// Test de la méthode initializeFromFile avec un fichier invalide
TEST(FileManagerTest, InitializeFromFileInvalid) {
    // Simuler une tentative d'ouverture d'un fichier qui échoue
    std::ifstream fileMock("/path/to/invalid/file.txt");
    if (!fileMock) {
        FAIL() << "Unable to open file for reading.";
    }

    File_manager fm;
    GridMock grid;

    // Lancer l'exception si le fichier est introuvable
    EXPECT_THROW(fm.initializeFromFile(grid), std::runtime_error);
}

// Test de la méthode saveFile
TEST(FileManagerTest, SaveFileValid) {
    GridMock grid;
    File_manager fm;

    std::string filePath = "/path/to/save/file.txt";
    std::string saveDirectory = "/save/directory/";

    // Simuler un appel pour la sauvegarde de fichier
    EXPECT_CALL(grid, getRows()).WillOnce(testing::Return(3));
    EXPECT_CALL(grid, getCols()).WillOnce(testing::Return(3));
    EXPECT_CALL(grid, getTotalGrid()).WillOnce(testing::Return(std::vector<std::vector<Cell>>{{Cell(true), Cell(false), Cell(true)}, {Cell(false), Cell(true), Cell(false)}, {Cell(true), Cell(true), Cell(false)}}));

    // Simuler l'écriture du fichier
    std::ofstream outputFileMock(saveDirectory + "save_1.txt");
    outputFileMock << "3 3\n010\n101\n111\n";
    outputFileMock.close();

    // Appeler la méthode saveFile
    fm.saveFile(grid, 1);

    // Si aucune exception n'a été lancée, le test est réussi
}

// Test de la méthode saveFile avec un fichier introuvable
TEST(FileManagerTest, SaveFileInvalid) {
    GridMock grid;
    File_manager fm;

    // Simuler une exception lors de l'écriture
    EXPECT_THROW(fm.saveFile(grid, 1), std::runtime_error);
}

