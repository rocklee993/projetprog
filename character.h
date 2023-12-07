#ifndef CHARACTER_H
#define CHARACTER_H


class character
{
    public:
        character(int x,int y,double health,double pointForce,bool player,char symbol);
        virtual void move(int dx, int dy) = 0;
        virtual ~character();
        virtual void attack(double force) = 0;
        virtual void getDamage(double damage) = 0;
        int getX() const;
        int getY() const;
        int getHealth() const;
        char getSymbol() const;
        double getPointForce() const;

    private:
         double d_health;
        int d_posX,d_posY;
        bool d_isPlayer;
        char d_symbol;
        double d_pointForce;
};

#endif // CHARACTER_H
