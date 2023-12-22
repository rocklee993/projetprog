#include "character.h"
#include "goto_xy_windows.h"

character::character(int x,int y,double health,double pointForce,bool player,char symbol):d_posX{x},d_posY{y},d_health{health},d_pointForce{pointForce},d_isPlayer{player},d_symbol{symbol},d_nextDirection{0,0}
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

void character::getDamage(double damage)
{
    d_health -= damage;
    if(d_health <= 0)
    {
        d_health = 0;
    }
}

void character:: move() {
d_posX += d_nextDirection[0];
d_posY += d_nextDirection[1];
d_nextDirection[0] = 0;
d_nextDirection[1] = 0;

}


std::vector<int> character::getNextDirection() const {
return d_nextDirection;
}

