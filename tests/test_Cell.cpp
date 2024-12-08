#include <gtest/gtest.h>
#include "../Cell.h"

// Test du constructeur Cell
TEST(CellTest, ConstructorTest) {
    // Initialisation d'une cellule avec état "vivant" et sans obstacle
    Cell cell(true, false);

    // Vérification des valeurs des attributs après la construction
    EXPECT_TRUE(cell.getState());    // La cellule doit être vivante
    EXPECT_FALSE(cell.getIsObstacle()); // La cellule ne doit pas être un obstacle
}

// Test de setAlive
TEST(CellTest, SetAliveTest) {
    Cell cell(false, false);  // Cellule morte et sans obstacle

    // La cellule doit être morte initialement
    EXPECT_FALSE(cell.getState());

    // Mettre la cellule vivante
    cell.setAlive(true);
    EXPECT_TRUE(cell.getState());  // La cellule doit être vivante

    // Mettre la cellule morte
    cell.setAlive(false);
    EXPECT_FALSE(cell.getState());  // La cellule doit être morte
}

// Test de setAlive avec un obstacle
TEST(CellTest, SetAliveWithObstacleTest) {
    Cell cell(false, true);  // Cellule morte et obstacle

    // La cellule doit être morte et un obstacle
    EXPECT_FALSE(cell.getState());
    EXPECT_TRUE(cell.getIsObstacle());

    // Tentons de changer l'état à vivant, mais la cellule est un obstacle
    cell.setAlive(true);
    EXPECT_FALSE(cell.getState());  // La cellule doit rester morte, car c'est un obstacle
}

// Test de getIsObstacle
TEST(CellTest, GetIsObstacleTest) {
    Cell cell(false, true);  // Cellule morte et obstacle

    // Vérification de l'état de l'obstacle
    EXPECT_TRUE(cell.getIsObstacle());

    // Changer l'état de l'obstacle
    cell.setIsObstacle(false);
    EXPECT_FALSE(cell.getIsObstacle());
}

// Test de setIsObstacle
TEST(CellTest, SetIsObstacleTest) {
    Cell cell(false, false);  // Cellule morte et sans obstacle

    // La cellule ne doit pas être un obstacle initialement
    EXPECT_FALSE(cell.getIsObstacle());

    // Mettre la cellule en obstacle
    cell.setIsObstacle(true);
    EXPECT_TRUE(cell.getIsObstacle());  // La cellule doit maintenant être un obstacle

    // Retirer l'obstacle
    cell.setIsObstacle(false);
    EXPECT_FALSE(cell.getIsObstacle());  // La cellule ne doit plus être un obstacle
}

