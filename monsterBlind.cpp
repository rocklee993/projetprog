#include "monsterBlind.h"
#include "monster.h"


monsterBlind::monsterBlind(int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite):
    monster{x,y,health,pointForce,false,symbol,pourcentageHabilite}
{
    //ctor
}

void monsterBlind::chooseDirection(std::vector<std::pair<int, int>>& wallPositions,character* character)
{
monster::getRandomDirection(wallPositions);

}

