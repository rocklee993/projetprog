#include "doctest.h"
#include "gamemanager.h"

TEST_CASE("GameManager - Initialization") {
    ruins myRuins(5, 5);
    player myPlayer(2, 2, 100.0, 5.0, true, 'P', 2, 3);
    gamemanager myGameManager(myPlayer, myRuins);

    CHECK(myGameManager.getPlayer().getSymbol() == 'P');
    CHECK(myGameManager.getRuins().getWidth() == 5);
    CHECK(myGameManager.getMonsters().empty());
    CHECK_FALSE(myGameManager.isGameEnded());
}

TEST_CASE("GameManager - Add Monster") {
    ruins myRuins(5, 5);
    player myPlayer(2, 2, 100.0, 5.0, true, 'P', 2, 3);
    gamemanager myGameManager(myPlayer, myRuins);
    std::unique_ptr<monster> myMonster = std::make_unique<monster>(3, 3, 50, 4.0, false, 'M', 70);

    myGameManager.addMonster(std::move(myMonster));

    CHECK_FALSE(myGameManager.getMonsters().empty());
}

TEST_CASE("GameManager - Game Over") {
    ruins myRuins(5, 5);
    player myPlayer(2, 2, 0.0, 5.0, true, 'P', 2, 3);
    gamemanager myGameManager(myPlayer, myRuins);

    myGameManager.gameover();

    CHECK(myGameManager.isGameEnded());
}

TEST_CASE("GameManager - Check Wall") {
    ruins myRuins(5, 5);
    player myPlayer(2, 2, 100.0, 5.0, true, 'P', 2, 3);
    gamemanager myGameManager(myPlayer, myRuins);

    SUBCASE("Wall Exists") {
        CHECK(myGameManager.checkWall(0, 0));
        CHECK(myGameManager.checkWall(2, 0));
        CHECK(myGameManager.checkWall(0, 2));
    }

    SUBCASE("No Wall") {
        CHECK_FALSE(myGameManager.checkWall(2, 2));
        CHECK_FALSE(myGameManager.checkWall(4, 4));
    }
}

/*TEST_CASE("GameManager - Monster Turn") {
    ruins myRuins(5, 5);
    player myPlayer(2, 2, 100.0, 5.0, true, 'P', 2, 3);
    gamemanager myGameManager(myPlayer, myRuins);
    std::unique_ptr<monster> myMonster = std::make_unique<monster>(3, 3, 50, 4.0, false, 'M', 70);

    myGameManager.addMonster(std::move(myMonster));
    myGameManager.monsterTurn();

    CHECK(myPlayer.getHealth() < 100.0);
}*/





