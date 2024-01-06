#include "gamemanager.h"
#include <windows.h>
#include <algorithm>
#include <iostream>  // Include for std::cout and other stream-related functionality

#include <fstream>
#include <sys/stat.h>
#include <cstdlib>   // Include for std::exit
#include <fstream>
#include "player.h"  // Include for the player class

gamemanager::gamemanager(player& player, ruins& ruins)
:
    d_player{player},d_ruins{ruins},d_monsters{},d_gameEnded {false}
{

}

void gamemanager::addMonster(std::unique_ptr<monster> monster) {
     d_monsters.push_back(std::move(monster));
}


void gamemanager::gameover() {

d_gameEnded = true;

std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl << "GAMEOVER";
}



bool  gamemanager::checkWall(int x , int y) const {

 if(d_ruins.isWall(x, y)) {
  // For debugging purposes
    std::cout << "there is a wall in : (" << x << ", " << y << ")" << std::endl;

 return true;
 };
 return false;

}

void gamemanager::monsterTurn(){


 for (auto& m : d_monsters) {
    if(m->getSymbol() == 'm') {
    m->chooseDirection(d_ruins.getWallPositions());
    } else {
        m->chooseDirection(d_ruins.getWallPositions(),&d_player);
    }

    if (d_player.getX() == m->getX() && d_player.getY() == m->getY()) {
        m->attack(d_player);
        if (d_player.getHealth() <= 0) {
                gameover();
            }

    d_player.attack(*m); // it's working

     if (m->getHealth() <= 0 && m != nullptr ) {
    auto it = std::remove(d_monsters.begin(), d_monsters.end(), m);
    d_monsters.erase(it, d_monsters.end());

}
        }
        }



         // it's working


 }
void gamemanager::playerTurn() {


    d_player.chooseDirection(d_ruins.getWallPositions());
    int newX = d_player.getX();
    int newY = d_player.getY();

    if (d_ruins.isTreasure(newX,newY))
    {
        exit(0);
    }

   for (auto it = d_ruins.getCoinPositions().begin(); it != d_ruins.getCoinPositions().end(); )
{
    if (newX == it->first && newY == it->second)
    {
        d_player.addbourse();
        cout << "!!!!!!!!!!" << std::endl;
        Sleep(1000);
        cout << "You hit the jackpot! You collected a coin." << std::endl;
        it = d_ruins.getCoinPositions().erase(it);
    }
    else
    {
        ++it;
    }
}


      for (auto& m : d_monsters) {
            if(m != nullptr) {

    if (d_player.getX() == m->getX() && d_player.getY() == m->getY()) {
        d_player.attack(*m); // it's working

     if (m->getHealth() <= 0 && m != nullptr ) {
    auto it = std::remove(d_monsters.begin(), d_monsters.end(), m);
    d_monsters.erase(it, d_monsters.end());

} else {
    m->attack(d_player);
       if (d_player.getHealth() <= 0) {
                gameover();
            }
}

            }


    }

}
}
/*
bool gamemanager::isSaveFileEmpty(const std::string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) != 0);
}
*/
bool gamemanager::isSaveFileEmpty(const std::string& filename) {
    struct stat buffer;
    if (stat(filename.c_str(), &buffer) != 0) {
        std::cout << "File " << filename << " not found." << std::endl;
    } else {
        std::cout << "File " << filename << " found." << std::endl;
    }
    return (stat(filename.c_str(), &buffer) != 0);
}

void gamemanager::startGame() {

   std::string reponse;
    if (!isSaveFileEmpty("save.txt")) {
        //non vide
        do{
            std::cout << "Would you like to pick up where you left off (Y/N) ?" << std::endl;
            std::cin >> reponse;
        } while(reponse=="Y" || reponse=="N");
        if(reponse=="Y"){
                d_ruins.loadGame(d_player, d_monsters);
        }
    }

   while (!d_gameEnded) {


    d_ruins.updateRuins(d_player, d_monsters);

    playerTurn();
    monsterTurn();
   // d_player.showstats(cout);
// ff
}
d_ruins.saveGame(d_player, d_monsters);
}
void gamemanager::win() {

}
