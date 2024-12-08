#include <gtest/gtest.h>
#include "../Game.h"

TEST(GameTest, TestInitialValues) {
    // Making a game object from the Game class
    Game game;

    // Check the initial value
    EXPECT_EQ(game.getMode(), 0);        // The mode should be set at 0
    EXPECT_EQ(game.getGenerations(), 10); // The generations should be set at 10
    EXPECT_EQ(game.getDelay(), 500); // The delay should be set at 500`
}

TEST(GameTest, TestSetGenerations) {
    Game game;
    game.setGenerations(20);
    EXPECT_EQ(game.getGenerations(), 20); // Check if there is 20 generations
}

TEST(GameTest, TestSetMode) {
    Game game;
    game.setMode(1);
    EXPECT_EQ(game.getMode(), 1); // Check if the mode is well updated
}

TEST(GameTest, TestSetDelay) {
    Game game;
    game.setDelay(1000);
    EXPECT_EQ(game.getDelay(), 1000); // Check if the delay is well updated
}
