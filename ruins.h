#ifndef RUINS_H
#define RUINS_H
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "character.h"
#include "player.h"
#include "monster.h"
#include <ctime>
using std::string;
using std::cout;


class ruins
{
    public:
        ruins(int x,int y);
        void initializeRuins(player &p,monster &m);
        void render();
        bool isWall(int x, int y) const;
        bool isOutOfBounds(int x, int y) const;
        bool isGold(int x, int y) const;
        bool isTreasure(int x, int y) const;


        const std::vector<std::pair<int, int>>& getCoinPositions() const ;


    private:
        int width,height;
        bool wall = false;
        bool coin = false;
        bool treasure = false;


        std::vector<std::vector<char>> grid;
        static constexpr char wallchar = '%';
        std::vector<std::pair<int, int>> coinPositions;
        static constexpr char coinchar = '$';
        static constexpr char treasurechar = 't';


};

#endif // RUINS_H
