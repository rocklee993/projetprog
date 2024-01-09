#include "doctest.h"
#include "character.h"

TEST_CASE("Character - Initialization") {
    character player(1, 2, 100.0, 5.0, true, 'P');

    CHECK(player.getX() == 1);
    CHECK(player.getY() == 2);
    CHECK(player.getHealth() == 100.0);
    CHECK(player.getPointForce() == 5.0);
    CHECK(player.getSymbol() == 'P');
    CHECK(player.getNextDirection()[0] == 0);
    CHECK(player.getNextDirection()[1] == 0);
}

TEST_CASE("Character - Damage") {
    character enemy(3, 4, 50.0, 3.0, false, 'E');
    enemy.getDamage(20.0);

    CHECK(enemy.getHealth() == 30.0);
}

TEST_CASE("Character - Move") {
    character player(1, 2, 100.0, 5.0, true, 'P');
    player.setNextDirection(1, 0); // Move right
    player.move();

    CHECK(player.getX() == 2);
    CHECK(player.getY() == 2);
}

TEST_CASE("Character - Check Wall") {
    character player(3, 3, 100.0, 5.0, true, 'P');
    std::vector<std::pair<int, int>> wallPositions = {{4, 3}, {3, 4}};

    SUBCASE("No wall in the way") {
        player.setNextDirection(1, 0); // Move right
        CHECK_FALSE(player.checkWall(wallPositions));
    }

    SUBCASE("Wall in the way") {
        player.setNextDirection(0, 1); // Move down
        CHECK(player.checkWall(wallPositions));
    }
}
