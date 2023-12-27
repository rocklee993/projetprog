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
        int width() const;
        int height() const;


        std::vector<std::pair<int, int>>& getCoinPositions() ;



    private:
        int d_width;
        int d_height;
        bool wall = false;
        bool coin = false;
        bool treasure = false;


        std::vector<std::vector<char>> grid;
        static constexpr char wallchar = '#';
        std::vector<std::pair<int, int>> coinPositions;
        static constexpr char coinchar = '$';
        static constexpr char treasurechar = 't';


};

#endif // RUINS_H
