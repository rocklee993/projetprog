#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using std::ostream;
#include "character.h"


class player : public character
{
    public:
        player(int x,int y,double health,double pointForce,bool player,char symbol);
        int bourse() const;
        void showstats(std::ostream& ost) const;
        bool treasurefound();
        void addbourse();
        void foundTreasure();
        void attack(double force ,&monster monster) override;
        void getDamage(double damage) override;
          void move(int dx,int dy) override;


    protected:

    private:
        int d_bourse;
        bool d_treasurefound;
};

#endif // PLAYER_H
