#include "monster.h"

monster::monster(int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite):
character{x,y,health,pointForce,false,symbol},d_pourcentageHabilite{pourcentageHabilite}
{

}

void monster::attack(character& character) {
    double force = character::getPointForce()*d_pourcentageHabilite;
    character.getDamage(force);
}


void monster::getRandomDirection(std::vector<std::pair<int, int>>& wallPositions) {

do {
  for(int i=0; i< 2;i++){
     d_nextDirection[i] = rand() % 3 - 1;// Génère un nombre aléatoire entre -1 et 1
  }

} while(checkWall(wallPositions));

move();


}




