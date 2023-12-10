#ifndef MONSTER_H
#define MONSTER_H
#include <memory>
#include <vector>
#include "character.h"
#include "player.h"

class monster : public character
{
    public:
        monster(int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite);
        void getDamage(double damage) override;
        void attack(character& character) override ;
        void  getRandomDirection();
        void chooseDirection() override;

    private:
        int d_pourcentageHabilite;
        static constexpr bool d_isPlayer = false;


};


#endif // MONSTER_H
