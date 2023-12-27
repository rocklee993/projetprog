#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using std::ostream;
#include "character.h"
#include "monster.h"
#include "equipement.h"


class player : public character
{
    public:
        player(int x,int y,double health,double pointForce,bool player,char symbol, int solide_epee=5, int solide_armure=5);
        int bourse() const;
        void showstats(std::ostream& ost) const;
        bool treasurefound();
        char getDirection() const;
        void addbourse();
        void foundTreasure();
        void attack(character& character) override;
        void chooseDirection() override;


    private:
        int d_bourse;
        bool d_treasurefound;
        epee d_epee;
        armure d_armure;
};

#endif // PLAYER_H
