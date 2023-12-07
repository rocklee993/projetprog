#include "player.h"
#include <string>
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

void player::attack((double force ,&monster monster)) {
// a continuer
}

void player::getDamage(double damage) {
// a continuer
}

void player::move(int dx,int dy){
// a continuer
}
