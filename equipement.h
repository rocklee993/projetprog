#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H


class equipement
{
     public:
        equipement(int solide);
        void perd();
        void recupere(int piece);
        int solide() const;


    private:
        int d_solide;
};

class epee: public equipement
{
    public:
        epee(int solide);

};

class armure: public equipement
{
    public:
        armure(int solide);


};
#endif // EQUIPEMENT_H
