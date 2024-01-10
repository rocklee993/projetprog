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


//ajoute des monstres dans un tableau pour les mettres ensuite sur le terrain
void gamemanager::addMonster(std::unique_ptr<monster> monster) {
     d_monsters.push_back(std::move(monster));
}


void gamemanager::gameover() {

d_gameEnded = true;

std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl << "GAMEOVER";
}


//verifier si le character este n face d'un mur
bool  gamemanager::checkWall(int x , int y) const {

 if(d_ruins.isWall(x, y)) {
  // For debugging purposes
    std::cout << "there is a wall in : (" << x << ", " << y << ")" << std::endl;

 return true;
 };
 return false;

}


//deplacement des monstres
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
    //d_player.chooseDirections();
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
void gamemanager::startGame() {



   while (!d_gameEnded) {
    d_ruins.initializeRuins(d_player, d_monsters);
    d_ruins.render();
    playerTurn();
    monsterTurn();
   // d_player.showstats(cout);
// ff
}
}
void gamemanager::win() {

}
