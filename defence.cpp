#include "defence.h"

defence::defence(int solide):
    d_solide{solide}
{
    //ctor
}


int defence::solide() const
{
    return d_solide;
}

epee::epee(int solide):
    defence{solide}
{
    //ctor
}

armure::armure(int solide):
    defence{solide}
{
    //ctor
}

void defence::perd()
{
    d_solide -=1;
}


void defence::recupere(int piece)
{
    d_solide += piece;
}
