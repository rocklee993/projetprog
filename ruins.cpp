#include "ruins.h"
#include "character.h"
#include <cstdlib>
#include <fstream>

ruins::ruins(int x, int y): width {x}, height {y}
{
    grid = std::vector<std::vector<char>>(y, std::vector<char>(x, '.'));
}


void ruins::initializeRuins(player& p, std::vector<std::unique_ptr<monster>>& monsters) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
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

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                grid[i][j] = wallchar;
                wallPositions.push_back(std::make_pair(j, i));
            } else {
                if (wall == false && coin == false) {
                    if (grid[i][j] == '.') {
                        if (rand() % 100 < 20) {
                            grid[i][j] = wallchar;
                            wallPositions.push_back(std::make_pair(j, i));
                        }
                        if (rand() % 100 < 20) {
                            // coinPositions.push_back({j, i});
                            // grid[i][j] = coinchar;
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


void ruins::updateRuins(player& p, std::vector<std::unique_ptr<monster>>& monsters) {
    // Efface l'écran sous Windows
    system("cls");

    // Réinitialise le terrain
    initializeRuins(p, monsters);

    // Met à jour les positions du joueur et des monstres
    int px = p.getX();
    int py = p.getY();
    grid[py][px] = p.getSymbol();

    for (auto& m : monsters) {
        int mx = m->getX();
        int my = m->getY();
        grid[my][mx] = m->getSymbol();
    }

    // Affiche le terrain mis à jour
    render();
}

void ruins::saveGame(player& p, std::vector<std::unique_ptr<monster>>& monsters) {
    std::ofstream saveFile("C:/Users/H O P E/Downloads/pp/save.txt"); // Changez le nom du fichier selon vos besoins

    // Écriture des données du terrain
    saveFile << height << " " << width << "\n";
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            saveFile << grid[i][j] << " ";
        }
        saveFile << "\n";
    }

    // Écriture des données du joueur
    saveFile << p.getX() << " " << p.getY() << " " << p.getHealth() << " " << p.getPointForce() << "\n";

    // Écriture des données des monstres
    for (const auto& m : monsters) {
        saveFile << m->getX() << " " << m->getY() << " " << m->getHealth() << " " << m->getPointForce() << "\n";
    }

    saveFile.close();
}

void ruins::loadGame(player& p, std::vector<std::unique_ptr<monster>>& monsters) {
    std::ifstream saveFile("C:/Users/H O P E/Downloads/pp/save.txt"); // Changez le nom du fichier selon vos besoins

    // Lecture des données du terrain
    saveFile >> height >> width;
    grid.resize(height, std::vector<char>(width, '.'));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            saveFile >> grid[i][j];
        }
    }

    // Lecture des données du joueur
    int playerX, playerY;
    double playerHealth, playerPointForce;
    saveFile >> playerX >> playerY >> playerHealth >> playerPointForce;


    player play(playerX, playerY,playerHealth,playerPointForce,true,'p');

    // Lecture des données des monstres
    int monsterX, monsterY;
    double monsterHealth, monsterPointForce;
    while (saveFile >> monsterX >> monsterY >> monsterHealth >> monsterPointForce) {
        monsters.push_back(std::make_unique<monster>(monsterX, monsterY, monsterHealth, monsterPointForce, false, 'm', 20));
    }

    saveFile.close();
}



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









