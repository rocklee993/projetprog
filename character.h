#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>

class character
{
    public:
        character(int x,int y,double health,double pointForce,bool player,char symbol);
        virtual ~character();
        void move();
        virtual void chooseDirection() = 0;
        virtual void getDamage(double damage) = 0 ;
        virtual void attack(character& character) = 0 ;
        int getX() const;
        int getY() const;
        int getHealth() const;
        char getSymbol() const;
        double getPointForce() const;
        std::vector<int> getNextDirection() const;

    protected:
        double d_health;
        int d_posX,d_posY;
        bool d_isPlayer;
        char d_symbol;
        double d_pointForce;
        std::vector<int> d_nextDirection;
};

#endif // CHARACTER_H
