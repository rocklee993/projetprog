#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using std::ostream;
#include "character.h"
#include "monster.h"


class player : public character
{
    public:
        player(int x,int y,double health,double pointForce,bool player,char symbol);
        int bourse() const;
        void showstats(std::ostream& ost) const;
        bool treasurefound();
        char getDirection() const;
        void addbourse();
        void foundTreasure();
        void attack(character& character) override;
        void getDamage(double damage) override;
        void chooseDirection() override;



    protected:

    private:
        int d_bourse;
        bool d_treasurefound;
};

#endif // PLAYER_H
