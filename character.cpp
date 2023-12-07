#include "character.h"

character::character(int x,int y,double health,double pointForce,bool player,char symbol):d_posX{x},d_posY{y},d_health{health},d_pointForce{pointForce},d_isPlayer{player},d_symbol{symbol}
{
    //ctor
}

character::~character()
{
    //dtor
}
int character::getX()const{
    return d_posX;
}
int character::getY()const{
    return d_posY;
}

int character::getHealth()const{
    return d_health;
}
char character::getSymbol()const{
    return d_symbol;
}
double character::getPointForce()const{
    return d_pointForce;
}
void character::move(int dx, int dy){

    d_posX += dx;
    d_posY += dy;
}
