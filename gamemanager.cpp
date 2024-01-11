#include "gamemanager.h"
#include <windows.h>
#include <algorithm>
#include <iostream>  // Include for std::cout and other stream-related functionality
#include <cstdlib>   // Include for std::exit
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

std::cout << "!!!!!GAMEOVER!!!!!" << std::endl;
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
                 std::cout << "**** FIGHT (TATAKAY) ****" << std:: endl;
        m->attack(d_player);
        if (d_player.getHealth() <= 0) {
                d_gameEnded = true;
                return;
            }

    d_player.attack(*m); // it's working

     if (m->getHealth() <= 0 && m != nullptr ) {
    auto it = std::remove(d_monsters.begin(), d_monsters.end(), m);
    d_monsters.erase(it, d_monsters.end());
     std::cout << "****The player defeated the enemy, good job :)****" << std:: endl;

}
        }
        }



         // it's working


 }

void gamemanager::playerTurn() {


    d_player.chooseDirection(d_ruins.getWallPositions());
     system("cls");
    int newX = d_player.getX();
    int newY = d_player.getY();

    if (d_ruins.isTreasure(newX,newY))
    {
       // d_player.foundTreasure();
       d_ruins.setExit();
    }

    if(d_ruins.getExit()) {

        std::vector<int> exitPos = d_ruins.getExitPosition();

    if(newX == exitPos[1] && newY == exitPos[0]) {
      win();
    }
    }


   for (auto it = d_ruins.getCoinPositions().begin(); it != d_ruins.getCoinPositions().end(); )
{
    if (newX == it->first && newY == it->second)
    {
        d_player.addbourse();
        cout << "!!!!!!!!!!" << std::endl;
        Sleep(1000);
        cout << "****You hit the jackpot! You collected a coin.****" << std::endl;
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
                std::cout << "**** FIGHT (TATAKAY) ****" << std:: endl;
        d_player.attack(*m); // it's working

     if (m->getHealth() <= 0 && m != nullptr ) {
    auto it = std::remove(d_monsters.begin(), d_monsters.end(), m);
    d_monsters.erase(it, d_monsters.end());
    std::cout << " ****The player defeated the enemy, good job :)****" << std:: endl;

} else {
    m->attack(d_player);
       if (d_player.getHealth() <= 0) {
                  d_gameEnded = true;
            }
}
            }


    }

}
}
void gamemanager::startGame() {


   while (!d_gameEnded) {
         d_player.showstats(cout);
    d_ruins.initializeRuins(d_player, d_monsters);
    d_ruins.render();
        instruction();
    playerTurn();
    monsterTurn();



// ff
}
gameover();


}
void gamemanager::win() {
       d_player.foundTreasure();
        cout << "BRAVO! You are a hero ! :D";
        exit(0);
}

void gamemanager::instruction() {
    std::cout << "***********Instructions for Movement :***********" << std::endl;
    std::cout << "*   (left up)           (up)         (right up)  *" << std::endl;
    std::cout << "*               7        8        9              *" << std::endl;
    std::cout << "*      (left)   4        5        6  (right)     *" << std::endl;
    std::cout << "*               1        2        3              *" << std::endl;
    std::cout << "* (left down)          (down)        (right down)*" << std::endl;
    std::cout << "**************************************************" << std::endl;
}
