#ifndef DEFENCE_H
#define DEFENCE_H
#include <iostream>


class defence
{
     public:
        defence(int solide);
        void perd();
        void recupere(int piece);
        int solide() const;

    protected:

    private:
        int d_solide;
};

class epee: public defence
{
    public:
        epee(int solide);

};

class armure: public defence
{
    public:
        armure(int solide);


};


#endif // DEFENCE_H
