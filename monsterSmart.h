#ifndef MONSTERSMART_H
#define MONSTERSMART_H
#include "character.h"

#include "monster.h"
class monsterSmart : public monster
{
public:
monsterSmart(int x, int y, int health, double pointForce, bool player, char symbol, int pourcentageHabilite);
    void chooseDirection(std::vector<std::pair<int, int>>& wallPositions,character* character =nullptr) override;
    void theShortestRoadToPlayer(int targetX,int targetY,std::vector<std::pair<int, int>>& wallPositions);
};

#endif // MONSTERSMART_H
