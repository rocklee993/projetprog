#include "equipement.h"

equipement::equipement(int solide):
    d_solide{solide}
{
    //ctor
}


int equipement::solide() const
{
    return d_solide;
}

epee::epee(int solide):
    equipement{solide}
{
    //ctor
}

armure::armure(int solide):
    equipement{solide}
{
    //ctor
}

void equipement::perd()
{
    d_solide -=1;
    if(d_solide <= 0)
    {
        d_solide = 1;
    }
}


void equipement::recupere(int piece)
{
    d_solide += piece;
}
