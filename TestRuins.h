#include "doctest.h"
#include "ruins.h"
#include "player.h"
#include "monster.h"

TEST_CASE("Ruins - Initialization") {
    ruins myRuins(5, 5);

    CHECK(myRuins.getWidth() == 5);
    CHECK(myRuins.getHeight() == 5);
}

TEST_CASE("Ruins - Initialize Ruins") {
    ruins myRuins(5, 5);
    player myPlayer(2, 2, 100.0, 5.0, true, 'P', 2, 3);
    std::vector<std::unique_ptr<monster>> monsters;

    myRuins.initializeRuins(myPlayer, monsters);

    CHECK(myRuins.isWall(0, 0));
    CHECK(myRuins.isWall(0, 2));
    CHECK(myRuins.isWall(2, 0));

}

TEST_CASE("Ruins - Get Coin Positions") {
    ruins myRuins(5, 5);
    player myPlayer(2, 2, 100.0, 5.0, true, 'P', 2, 3);
    std::vector<std::unique_ptr<monster>> monsters;

    myRuins.initializeRuins(myPlayer, monsters);

    auto coinPositions = myRuins.getCoinPositions();

    CHECK_FALSE(coinPositions.empty());
}



// Add more test cases based on the specific behavior of your ruins class

