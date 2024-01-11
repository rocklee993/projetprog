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
        virtual void attack(character& character) = 0 ;
        void getDamage(double damage);
        double getRandomNumber() const;
        int getX() const;
        int getY() const;
        int getHealth() const;
        char getSymbol() const;
        double getPointForce() const;
        std::vector<int> getNextDirection() const;
        static constexpr double pourcentageReductionDamage {0.9};


    protected:
        double d_health;
        int d_posX,d_posY;
        bool d_isPlayer;
        char d_symbol;
        double d_pointForce;
        std::vector<int> d_nextDirection;
};

#endif // CHARACTER_H
