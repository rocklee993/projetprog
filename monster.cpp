#include "monster.h"

monster::monster(int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite):
character{x,y,health,pointForce,false,'m'},d_pourcentageHabilite{pourcentageHabilite}
{

}

void monster::attack((double force ,&player player)) {
player.getDamage(force);
}

void monster::getDamage(double damage) {
 d_health -= damage;
}

vector<int> monster::getRandomDirection(){

    vector<int> position{0,0};
    std::random_device rd;
    std::mt19937 gen(rd());
    position[0] = std::uniform_int_distribution<int> dis(-1, 1);
    position[1] = std::uniform_int_distribution<int> dis(-1, 1);
    return position;
}

}

