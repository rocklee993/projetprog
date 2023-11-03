#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using std::ostream;
#include "character.h"


class player : public character
{
    public:
        player(int x,int y);

        int bourse() const;
        void showstats(std::ostream& ost)const;
        bool treasurefound();
        void addbourse();
        void foundTreasure();
    protected:

    private:
        int d_bourse;
        bool d_treasurefound;
};

#endif // PLAYER_H
