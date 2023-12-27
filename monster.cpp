#include "monster.h"
#include "goto_xy_windows.h"

monster::monster(int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite):
character{x,y,health,pointForce,false,'m'},d_pourcentageHabilite{pourcentageHabilite}
{

}

void monster::attack(character& character) {
    double force = character::getPointForce()*d_pourcentageHabilite;
    character.getDamage(force);
}


void monster::turnLeft()
{
    d_posX -=1;

}

void monster::turnRigth()
{
    d_posX +=1;
}

void monster::turnHaut()
{
    d_posY +=1;
}

void monster::turnBas()
{
    d_posX -=1;

}

void  monster::getRandomDirection()
{
    d_posX +=1;
    goto_xy(d_posX, d_posY);
}




