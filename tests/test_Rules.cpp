#include "gtest/gtest.h"
#include "Rules.h"
#include "Cell.h"

// Rules constructor test (initialization of cell status)
TEST(RulesTest, TestConstructor) {
    // Make a cell with "true" state
    Rules rules(true);
    EXPECT_TRUE(rules.getState());  // Check if the cell's state is "true"

    // Make a cell with "false" state
    rules = Rules(false);
    EXPECT_FALSE(rules.getState());  // Check if the cell's state is false
}

// Test of the applyRules method for a living cell (state = true)
TEST(RulesTest, TestApplyRulesCellAlive) {
    Rules rules(true);  // Make a new rules with an alive cell
    Cell cell(true);  // Make an alive cell

    // Test the applyRules method with a number of living neighbors of 2 (the cell must remain alive).
    EXPECT_TRUE(rules.applyRules(cell, 2));

    // Test the applyRules method with a number of living neighbors of 3 (the cell must remain alive).
    EXPECT_TRUE(rules.applyRules(cell, 3));

    // Test the applyRules method with a number of living neighbors other than 2 or 3 (the cell must die).
    EXPECT_FALSE(rules.applyRules(cell, 1));
    EXPECT_FALSE(rules.applyRules(cell, 4));
}

// Test the applyRules method for a dead cell (state = false)
    TEST(RulesTest, TestApplyRulesCellDead) {
    Rules rules(false);  // Make a rule with a dead cell
    Cell cell(false);  // Make a dead cell

    // ApplyRules test with 3 living neighbors (the cell must become alive)
    EXPECT_TRUE(rules.applyRules(cell, 3));

    // Test the applyRules method with a number of living neighbors other than 3 (the cell must remain dead).
    EXPECT_FALSE(rules.applyRules(cell, 1));
    EXPECT_FALSE(rules.applyRules(cell, 2));
    EXPECT_FALSE(rules.applyRules(cell, 4));
}
