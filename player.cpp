#include "player.h"
#include <string>
#include<ostream>

player::player(int x,int y,double health,double pointForce,bool player,char symbol):character(x,y,health,pointForce,true,'p') , d_bourse{0} , d_treasurefound{false}
{

}



int player::bourse() const{
    return d_bourse;
}
void player::addbourse(){
    d_bourse+=10;
}

void player::showstats(std::ostream& ost)const{
    ost<<"player stats : "<<std::endl;
    ost<<"gold :"<<d_bourse <<"$"<<std::endl;
    ost<<"health : "<< std::to_string(getHealth())<<std::endl;
    ost<<"Force Point :"<<std::to_string(getPointForce())<<std::endl;

}

bool player::treasurefound() {
    return d_treasurefound;
}
void player::foundTreasure() {
    d_treasurefound = true;
}

void player::attack(character& character) {
// a continuer
}

void player::getDamage(double damage) {
// a continuer
}

void player:: chooseDirection() {
    bool validecharacter;

    do {
        validecharacter = true;
        char character = getDirection();

        switch (character) {
            case '2':
                d_nextDirection[1] = -1;
                break;
            case '4':
                d_nextDirection[0] = -1;
                break;
            case '8':
                d_nextDirection[1] = 1;
                break;
            case '6':
                d_nextDirection[0] = 1;
                break;
            case '1':
                d_nextDirection[0]= -1;
                d_nextDirection[1] = -1;
                break;
            case '3':
                d_nextDirection[0]= 1;
                d_nextDirection[1] = -1;
                break;
            case '7':
                d_nextDirection[0] = -1;
                d_nextDirection[1] = 1;
                break;
            case '9':
                d_nextDirection[0] = 1;
                d_nextDirection[1] = 1;
                break;
            case '5':
                std::cout << "Player chose not to move" << std::endl;
                break;
            default:
                std::cout << "Invalid direction. Please use 1/2/3/4/5/6/7/8/9." << std::endl;
                valideDirection = false;
                continue;
        }

    } while (valideDirection == false);

}

char  player::getDirection() const
{
    std::cout << "What will be your next move? (1/2/3/4/5/6/7/8/9): " << std::endl;
    char direction;
    std::cin >> direction;
    return direction;
}
