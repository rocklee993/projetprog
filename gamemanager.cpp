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
        cout << "hello";


    if(m->getSymbol() == 'm') {
    m->chooseDirection(d_ruins.getWallPositions());
    } else {
        m->chooseDirection(d_ruins.getWallPositions(),&d_player);
    }
    int newX = m->getX();
    int newY = m->getY();
        }


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


<<<<<<< HEAD
      for (auto& m : d_monsters) {
    if (d_player.getX() == m->getX() && d_player.getY() == m->getY()) {
        d_player.attack(*m); // it's working

    //   d_monsters.erase(
    //std::remove_if(d_monsters.begin(), d_monsters.end(),
      //  [](const std::unique_ptr<monster>& m) {
        //    return m != nullptr && m->getHealth() <= 0;
       // }),
   // d_monsters.end());

        if (m != nullptr) {
=======
      for (auto it = d_monsters.begin(); it != d_monsters.end(); ) {
    auto& m = *it;

    if (d_player.getX() == m->getX() && d_player.getY() == m->getY()) {
        d_player.attack(*m);

        if (m->getHealth() > 0) {
>>>>>>> lyes
            m->attack(d_player);
            if (d_player.getHealth() <= 0) {
                gameover();
            }
<<<<<<< HEAD
        }
    }

=======
        } else {
            // Monster is dead
            cout << "Monster defeated!" << std::endl;
            it = d_monsters.erase(it);  // Remove the monster from the vector
            continue;  // Skip the rest of the loop
        }
    }

    ++it;  // Move to the next monster
>>>>>>> lyes
}


d_player.showstats(cout);

}
void gamemanager::startGame() {


   while (!d_gameEnded) {
    d_ruins.initializeRuins(d_player, d_monsters);
    d_ruins.render();
    playerTurn();
    monsterTurn();
}
}
void gamemanager::win() {

}



