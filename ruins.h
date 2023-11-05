#ifndef RUINS_H
#define RUINS_H
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
class ruins
{
    public:
        ruins(int x,int y);
        void initializeRuins(player &p);
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
