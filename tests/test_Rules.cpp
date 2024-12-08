#include "gtest/gtest.h"
#include "Rules.h"
#include "Cell.h"

// Test du constructeur Rules (initialisation de l'état de la cellule)
TEST(RulesTest, TestConstructor) {
    // Crée une cellule avec état 'true'
    Rules rules(true);
    EXPECT_TRUE(rules.getState());  // Vérifie que l'état de la cellule est correct (true)

    // Crée une cellule avec état 'false'
    rules = Rules(false);
    EXPECT_FALSE(rules.getState());  // Vérifie que l'état de la cellule est correct (false)
}

// Test de la méthode applyRules pour une cellule vivante (state = true)
TEST(RulesTest, TestApplyRulesCellAlive) {
    Rules rules(true);  // Crée une règle avec une cellule vivante
    Cell cell(true);  // Crée une cellule vivante

    // Test de la méthode applyRules avec un nombre de voisins vivants de 2 (la cellule doit rester vivante)
    EXPECT_TRUE(rules.applyRules(cell, 2));

    // Test de la méthode applyRules avec un nombre de voisins vivants de 3 (la cellule doit rester vivante)
    EXPECT_TRUE(rules.applyRules(cell, 3));

    // Test de la méthode applyRules avec un nombre de voisins vivants différent de 2 ou 3 (la cellule doit mourir)
    EXPECT_FALSE(rules.applyRules(cell, 1));
    EXPECT_FALSE(rules.applyRules(cell, 4));
}

// Test de la méthode applyRules pour une cellule morte (state = false)
TEST(RulesTest, TestApplyRulesCellDead) {
    Rules rules(false);  // Crée une règle avec une cellule morte
    Cell cell(false);  // Crée une cellule morte

    // Test de la méthode applyRules avec 3 voisins vivants (la cellule doit devenir vivante)
    EXPECT_TRUE(rules.applyRules(cell, 3));

    // Test de la méthode applyRules avec un nombre de voisins vivants différent de 3 (la cellule doit rester morte)
    EXPECT_FALSE(rules.applyRules(cell, 1));
    EXPECT_FALSE(rules.applyRules(cell, 2));
    EXPECT_FALSE(rules.applyRules(cell, 4));
}
