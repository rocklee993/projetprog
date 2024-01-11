#include "ruins.h"
#include "character.h"
#include <cstdlib>
#include <algorithm>  // Include the algorithm header for std::find


ruins::ruins(int x, int y): width {x}, height {y}
{
    grid = std::vector<std::vector<char>>(y, std::vector<char>(x, '.'));
}


void ruins::initializeRuins(player& p, std::vector<std::unique_ptr<monster>>& monsters) {
     for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] != wallchar && grid[i][j] != coinchar && grid[i][j] != treasurechar && grid[i][j] != exitchar)
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
int exitRow = 0;
int exitCol = 0;
    if(showExit) {

std::vector<int> exitPos = getExitPosition();
exitRow = exitPos[0];
exitCol = exitPos[1];
    }


// creation de la sortie

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
                if(showExit &&  (i == exitRow && j == exitCol)) {
                     grid[i][j] = exitchar;
                     auto it = std::find(wallPositions.begin(), wallPositions.end(), std::make_pair(j, i));
                if (it != wallPositions.end()) {
                wallPositions.erase(it);
             //       std::cout << "La position "<< j << " " << i << "supprimer" << std::endl;
  //  } else {
   //     std::cout << "La position "<< j << " " << i << "n'a pas été trouvée." << std::endl;
    }
                }
            else if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                grid[i][j] = wallchar;
                wallPositions.push_back(std::make_pair(j, i));
            }
              else {
                if (wall == false && coin == false) {
                    if (grid[i][j] == '.') {
                        if (rand() % 100 < 20) {
                            grid[i][j] = wallchar;
                            wallPositions.push_back(std::make_pair(j, i));
                        }
                        if (rand() % 100 < 20) {
                            coinPositions.push_back({j, i});
                            //grid[i][j] = coinchar;
                        }
                        if (!treasure) {
                            int treasureX, treasureY;
                            do {
                                srand(static_cast<unsigned int>(time(0)));
                                treasureX = rand() % (width - 2) + 1;
                                treasureY = rand() % (height - 2) + 1;
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
std::vector<std::pair<int, int>>& ruins::getWallPositions(){
return wallPositions;
};


void ruins::setExit() {
    createExit();
showExit = true;
std:: cout<< "You got the treasure! now go the the exit 'S'  "<< std::endl;
}
void ruins::createExit() {


std::srand(std::time(0));
int side = std::rand() % 4;  // 0: haut, 1: bas, 2: gauche, 3: droite
int exitRow, exitCol;

if (side == 0) {
    // Haut
    exitRow = 0;
    exitCol = std::rand() % width;
} else if (side == 1) {
    // Bas
    exitRow = height - 1;
    exitCol = std::rand() % width;
} else if (side == 2) {
    // Gauche
    exitRow = std::rand() % height;
    exitCol = 0;
} else {
    // Droite
    exitRow = std::rand() % height;
    exitCol = width - 1;
}
     exitPosition.push_back(exitRow);
        exitPosition.push_back(exitCol);

}
std::vector<int> ruins::getExitPosition() const {
return exitPosition;
}


bool ruins::getExit() const {
return showExit;
}






