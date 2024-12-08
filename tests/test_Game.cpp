#include <gtest/gtest.h>
#include "../Game.h"

TEST(GameTest, TestInitialValues) {
    // Créez un objet de la classe Game
    Game game;

    // Vérification des valeurs initiales
    EXPECT_EQ(game.getMode(), 0);        // Le mode devrait être initialisé à 0
    EXPECT_EQ(game.getGenerations(), 10); // Les générations devraient être initialisées à 10
    // Vous pouvez ajouter une vérification pour delay si un getter est disponible
    // EXPECT_EQ(game.getDelay(), 500); // Cette vérification dépend de l'existence d'un getter pour `delay`
}

TEST(GameTest, TestSetGenerations) {
    Game game;
    game.setGenerations(20);
    EXPECT_EQ(game.getGenerations(), 20); // Vérifie si la génération est correctement mise à jour
}

TEST(GameTest, TestSetMode) {
    Game game;
    game.setMode(1);
    EXPECT_EQ(game.getMode(), 1); // Vérifie si le mode est correctement mis à jour
}

TEST(GameTest, TestSetDelay) {
    Game game;
    game.setDelay(1000);
    // Ajoutez une méthode pour récupérer `delay` dans la classe Game pour que ce test fonctionne
    // EXPECT_EQ(game.getDelay(), 1000);
}
