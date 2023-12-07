#ifndef MONSTER_H
#define MONSTER_H
#include <memory>
#include <vector>
#include "character.h"


class monster : public character
{
    public:
        monster(int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite);
        void attack(double force, player& player) override;
        void getDamage(double damage) override;
        std::vector<int> getRandomDirection();

    private:
        int d_pourcentageHabilite;
        static constexpr bool d_isPlayer = false;


};


#endif // MONSTER_H
