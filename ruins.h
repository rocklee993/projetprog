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
        void initializeRuins(player &p,std::vector<std::unique_ptr<monster>>& monsters);
        void render();
        bool isWall(int x, int y) const;
        //bool isOutOfBounds(int x, int y) const;
        bool isGold(int x, int y) const;
        bool isTreasure(int x, int y) const;
        int heights() const;
        int widths() const;
        char grids(int x, int y) const;
        std::vector<std::pair<int, int>>& getCoinPositions();
        std::vector<std::pair<int, int>>& getWallPositions();


    private:
        bool isPositionEmpty(int x, int y, const player& p, const std::vector<std::unique_ptr<monster>>& monsters) const;
        int getRandomPosition(int max) const;
        int width,height;
        bool wall = false;
        bool coin = false;
        bool treasure = false;
        std::vector<std::pair<int, int>> wallPositions;
        std::vector<std::vector<char>> grid;
        static constexpr char wallchar = '#';
        std::vector<std::pair<int, int>> coinPositions;
        static constexpr char coinchar = '$';
        static constexpr char treasurechar = 't';


};

#endif // RUINS_H
