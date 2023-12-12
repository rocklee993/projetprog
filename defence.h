#ifndef DEFENCE_H
#define DEFENCE_H
#include <iostream>


class defence
{
     public:
        defence(int solide);
        //virtual void perd() = 0;
        //virtual void recupere(int piece) = 0;
        int solide() const;
        virtual ~defence() = default;

    protected:

    private:
        int d_solide;
};

class epee: public defence
{
    public:
        epee(int solide);
       // void perd() override;
        //void recupere(int piece) override;

    protected:

    private:
};

class armure: public defence
{
    public:
        armure(int solide);
        //void perd() override;
        //void recupere(int piece) override;

    protected:

    private:
};


#endif // DEFENCE_H
