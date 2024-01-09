#include "doctest.h"
#include "player.h"

TEST_CASE("Player - Initialization") {
    player myPlayer(1, 2, 100.0, 5.0, true, 'P', 2, 3);

    CHECK(myPlayer.getX() == 1);
    CHECK(myPlayer.getY() == 2);
    CHECK(myPlayer.getHealth() == 100.0);
    CHECK(myPlayer.getPointForce() == 5.0);
    CHECK(myPlayer.getSymbol() == 'P');
    CHECK(myPlayer.bourse() == 0);
    CHECK_FALSE(myPlayer.treasurefound());
}

TEST_CASE("Player - Bourse") {
    player myPlayer(1, 2, 100.0, 5.0, true, 'P', 2, 3);

    SUBCASE("Initial Bourse") {
        CHECK(myPlayer.bourse() == 0);
    }

    SUBCASE("Add Bourse") {
        myPlayer.addbourse();
        CHECK(myPlayer.bourse() == 10);
    }
}

TEST_CASE("Player - Stats") {
    player myPlayer(1, 2, 80.0, 7.5, true, 'P', 2, 3);

    std::ostringstream oss;
    myPlayer.showstats(oss);

    CHECK(oss.str() == "player stats : \ngold :0$\nhealth : 80\nForce Point :7.5\n");
}

TEST_CASE("Player - Treasure") {
    player myPlayer(1, 2, 100.0, 5.0, true, 'P', 2, 3);

    SUBCASE("Treasure Not Found") {
        CHECK_FALSE(myPlayer.treasurefound());
    }

    SUBCASE("Find Treasure") {
        myPlayer.foundTreasure();
        CHECK(myPlayer.treasurefound());
    }
}

TEST_CASE("Player - Attack") {
    player player1(1, 2, 100.0, 5.0, true, 'P', 2, 3);
    player player2(3, 4, 80.0, 6.0, false, 'E', 1, 2);

    player1.attack(player2);

    CHECK(player2.getHealth() < 80.0);  // Assuming attack causes damage
}

