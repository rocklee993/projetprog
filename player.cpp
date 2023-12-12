#include "player.h"

player::player(int x,int y, int solide_epee, int solide_armure):
    character(x,y,20,10,true,'p') , d_bourse{100} , d_treasurefound{false}, d_epee{solide_epee}, d_armure{solide_armure}

{
    //ctor
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
    ost<<"health : "<<d_health<<std::endl;
    ost<<"ad :"<<d_damage<<std::endl;

}

bool player::treasurefound() {
    return d_treasurefound;
}
void player::foundTreasure() {
    d_treasurefound = true;
}
