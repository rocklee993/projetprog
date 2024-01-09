#include "doctest.h"
#include "equipement.h"

TEST_CASE("Equipement - Initialization") {
    equipement myEquipement(5);

    CHECK(myEquipement.solide() == 5);
}

TEST_CASE("Equipement - Perd") {
    equipement myEquipement(5);

    myEquipement.perd();

    CHECK(myEquipement.solide() == 4);
}

TEST_CASE("Equipement - Recupere") {
    equipement myEquipement(5);

    myEquipement.recupere(2);

    CHECK(myEquipement.solide() == 7);
}

TEST_CASE("Epee - Initialization") {
    epee myEpee(8);

    CHECK(myEpee.solide() == 8);
}

TEST_CASE("Armure - Initialization") {
    armure myArmure(10);

    CHECK(myArmure.solide() == 10);
}



