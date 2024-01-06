#include "monster.h"

monster::monster(int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite):
character{x,y,health,pointForce,false,symbol},d_pourcentageHabilite{pourcentageHabilite}
{

}

void monster::attack(character& character) {
    double force = getPointForce()*d_pourcentageHabilite;
    character.getDamage(force);
    std::cout<< "The monster attack the player with '" << force << "' force";
}


void monster::getRandomDirection(std::vector<std::pair<int, int>>& wallPositions) {

do {

     d_nextDirection[0] = rand() % 3 - 1;// Génère un nombre aléatoire entre -1  et 0 et 1
     d_nextDirection[1] = rand() % 3 - 1;// Génère un nombre aléatoire entre -1  et 0 et 1


} while(checkWall(wallPositions));

move();


}




