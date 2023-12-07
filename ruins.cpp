#include "ruins.h"
#include "character.h"


#include <cstdlib>
ruins::ruins(int x, int y): width {x}, height {y}
{
    grid = std::vector<std::vector<char>>(y, std::vector<char>(x, '.'));
}


void ruins::initializeRuins(player& p,monster& m)
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (grid[i][j] != wallchar && grid[i][j] != coinchar && grid[i][j] != treasurechar ) grid[i][j] = '.';
        }
    }
    int x = p.getX();
    int y = p.getY();

    grid[y][x] = p.getSymbol();
    int x1 = m.getX();
    int y1 = m.getY();

    grid[y1][x1] = m.getSymbol();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                grid[i][j] = wallchar;
            }
            else
            {
                if(wall == false && coin == false)
                {
                    if(i!=p.getY() && j!=p.getX() && i!=m.getY() && j!=m.getX() && grid[i][j] != treasurechar)
                    {

                        if (rand() % 100 < 20)
                        {
                            grid[i][j] = wallchar;
                        }



                        if (rand() % 100 < 20 )
                        {
                            coinPositions.push_back({j, i});
                            //grid[i][j] = coinchar;

                        }
                        if (!treasure)
                        {
                            int treasureX, treasureY;
                            do
                            {
                                srand(static_cast<unsigned int>(time(0)));
                                treasureX = rand() % (width - 2) + 1;
                                treasureY = rand() % (height - 2) + 1;

                            }
                            while (grid[treasureY][treasureX] != '.');
                            grid[treasureY][treasureX] = treasurechar;
                            treasure = true;
                        }


                    }

                }

            }




        }
    }

    coin = true;
    wall = true;
}

const std::vector<std::pair<int, int>>& ruins::getCoinPositions() const
{
    return coinPositions;
}

void ruins::render()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << grid[i][j] <<' ';
        }
        std::cout << '\n';
    }
    cout<<'\n';

}
//bool ruins::isOutOfBounds(int x, int y) const
//{
  //  return (x < 0 || x >= width || y < 0 || y >= height);
//}

bool ruins::isWall(int x, int y) const
{

    return grid[y][x] == wallchar;
}

bool ruins::isGold(int x, int y) const
{

    return grid[y][x] == coinchar;
}
bool ruins::isTreasure(int x, int y) const
{

    return grid[y][x] == treasurechar;
}






