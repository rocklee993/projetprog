#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "character.h"
#include "defence.h"
using std::ostream;



class player : public character
{
    public:
        player(int x,int y, int solide_epee, int solide_armure);

        int bourse() const;
        void showstats(std::ostream& ost)const;
        bool treasurefound();
        void addbourse();
        void foundTreasure();
    protected:

    private:
        epee d_epee;
        armure d_armure;
        int d_bourse;
        bool d_treasurefound;
};

#endif // PLAYER_H
