#ifndef CHARACTER_H
#define CHARACTER_H


class character
{
    public:
        character(int x,int y,int health,int damage,bool player,char symbol);
        void move(int dx, int dy);
        virtual ~character();
        int getx()const;
        int gety()const;
        int gethealth()const;
        int getdamage()const;
        char getSymbol() const;

    protected:
        int d_health, d_damage;
        int d_posx,d_posy;
        bool d_isPlayer;
        char d_symbol;

    private:
};

#endif // CHARACTER_H
