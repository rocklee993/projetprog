#include "ruins.h"
#include "character.h"
#include <cstdlib>
#include "goto_xy_windows.h"

ruins::ruins(int x, int y): d_width {x}, d_height {y}
{
    grid = std::vector<std::vector<char>>(y, std::vector<char>(x, '.'));
}


void ruins::initializeRuins(player& p, std::vector<std::unique_ptr<monster>>& monsters) {
    for (int i = 0; i < d_height; i++) {
        for (int j = 0; j < d_width; j++) {
            if (grid[i][j] != wallchar && grid[i][j] != coinchar && grid[i][j] != treasurechar)
                grid[i][j] = '.';
        }
    }

    int x = p.getX();
    int y = p.getY();

    grid[y][x] = p.getSymbol();

    for (auto& m : monsters) {
        int mx = m->getX();
        int my = m->getY();
        grid[my][mx] = m->getSymbol();
    }

    for (int i = 0; i < d_height; i++) {
        for (int j = 0; j < d_width; j++) {
            if (i == 0 || i == d_height - 1 || j == 0 || j == d_width - 1) {
                grid[i][j] = wallchar;
            } else {
                if (wall == false && coin == false) {
                    if (i != p.getY() && j != p.getX() && grid[i][j] != treasurechar) {
                        if (rand() % 100 < 20) {
                            grid[i][j] = wallchar;
                        }
                        if (rand() % 100 < 20) {
                            // coinPositions.push_back({j, i});
                            // grid[i][j] = coinchar;
                        }
                        if (!treasure) {
                            int treasureX, treasureY;
                            do {
                                srand(static_cast<unsigned int>(time(0)));
                                treasureX = rand() % (d_width - 2) + 1;
                                treasureY = rand() % (d_height - 2) + 1;
                            } while (grid[treasureY][treasureX] != '.');
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
 std::vector<std::pair<int, int>>& ruins::getCoinPositions()
{
    return coinPositions;
}

void ruins::render()
{
    for (int i = 0; i < d_height; ++i)
    {
        for (int j = 0; j < d_width; ++j)
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

int ruins::width() const
{
    return d_width;
}


int ruins::height() const
{
    return d_height;
}






