#include "doctest.h"
#include "monster.h"

TEST_CASE("Monster - Initialization") {
    monster myMonster(1, 2, 100, 5.0, false, 'M', 80);

    CHECK(myMonster.getX() == 1);
    CHECK(myMonster.getY() == 2);
    CHECK(myMonster.getHealth() == 100);
    CHECK(myMonster.getPointForce() == 5.0);
    CHECK(myMonster.getSymbol() == 'M');
    CHECK(myMonster.getPourcentageHabilite() == 80);
}


TEST_CASE("Monster - Random Direction") {
    monster myMonster(1, 2, 100, 5.0, false, 'M', 80);
    std::vector<std::pair<int, int>> wallPositions = {{2, 2}, {3, 2}, {4, 2}, {3, 3}, {3, 4}};

    SUBCASE("Random Direction Without Wall") {
        myMonster.getRandomDirection(wallPositions);
        CHECK(myMonster.getNextDirection()[0] >= -1);
        CHECK(myMonster.getNextDirection()[0] <= 1);
        CHECK(myMonster.getNextDirection()[1] >= -1);
        CHECK(myMonster.getNextDirection()[1] <= 1);
    }


}
