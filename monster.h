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
        void attack(character& character) override ;
        void turnLeft();
        void turnRigth();
        void turnHaut();
        void turnBas();
        void  getRandomDirection();


    private:
        int d_pourcentageHabilite;
        static constexpr bool d_isPlayer = false;


};


#endif // MONSTER_H
