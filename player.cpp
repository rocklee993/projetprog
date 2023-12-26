#include "player.h"
#include <string>
#include<ostream>
#include "goto_xy_windows.h"

player::player(int x,int y,double health,double pointForce,bool player,char symbol, int solide_epee, int solide_armure):
    character(x,y,health,pointForce,true,symbol) , d_bourse{0} , d_treasurefound{false}, d_epee{solide_epee}, d_armure{solide_armure}
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
    double force = (character::getPointForce()+d_epee.solide())*0.9;
    character.getDamage(force);
}


void player::chooseDirection(std::vector<std::pair<int, int>>& wallPositions,character* character) {

    bool validecharacter = false;
        d_nextDirection[0] = 0;
        d_nextDirection[1] = 0;
    do {
        validecharacter = true;
        char inputChar = getDirection();

        switch (inputChar) {
            case '1':
                d_nextDirection[0] = -1;
                d_nextDirection[1] = 1;
                break;
            case '2':
                d_nextDirection[1] = 1;
                break;
            case '3':
                d_nextDirection[0] = 1;
                d_nextDirection[1] = 1;
                break;
            case '4':
                d_nextDirection[0] = -1;
                break;
            case '5':
                std::cout << "Player chose not to move" << std::endl;
                break;
            case '6':
                d_nextDirection[0] = 1;
                break;
            case '7':
                d_nextDirection[0] = -1;
                d_nextDirection[1] = -1;
                break;
            case '8':
                d_nextDirection[1] = -1;
                break;
            case '9':
                d_nextDirection[0] = 1;
                d_nextDirection[1] = -1;
                break;
            default:
                std::cout << "Invalid direction. Please use 1/2/3/4/5/6/7/8/9." << std::endl;
                validecharacter = false;
                continue;
        }

    } while (!validecharacter);

    if(checkWall(wallPositions)) {
            std::cout << "there is a wall in choose another direction: " << std::endl;
            chooseDirection(wallPositions);
    }
    move();



}
char  player::getDirection() const
{
    std::cout << "What will be your next move? (1/2/3/4/5/6/7/8/9): " << std::endl;
    char direction;
    std::cin >> direction;
    return direction;
}
