#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>

class character
{
    public:
        character(int x,int y,double health,double pointForce,bool player,char symbol);
        virtual ~character();
        void move();
        virtual bool checkWall(std::vector<std::pair<int, int>>& wallPositions) const;
        virtual void chooseDirection(std::vector<std::pair<int, int>>& wallPositions,character* character = nullptr ) = 0;
        void getDamage(double damage);
        virtual void attack(character& character) = 0 ;
        int getX() const;
        int getY() const;
        int getHealth() const;
        char getSymbol() const;
        double getPointForce() const;
        std::vector<int> getNextDirection() const;

    protected:
        double d_health; //point de vie
        int d_posX,d_posY; //coordonnée x et y du character
        bool d_isPlayer;
        char d_symbol; //symbole des characters
        double d_pointForce;
        std::vector<int> d_nextDirection;
};

#endif // CHARACTER_H
