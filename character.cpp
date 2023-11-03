#include "character.h"

character::character(int x,int y,int health,int damage,bool player,char symbol):d_posx{x},d_posy{y},d_health{health},d_damage{damage},d_isPlayer{player},d_symbol{symbol}
{
    //ctor
}

character::~character()
{
    //dtor
}
int character::getx()const{
    return d_posx;
}
int character::gety()const{
    return d_posy;
}
int character::getdamage()const{
    return d_damage;
}
int character::gethealth()const{
    return d_health;
}
char character::getSymbol()const{
    return d_symbol;
}
void character::move(int dx, int dy){

    d_posx += dx;
    d_posy += dy;
}
