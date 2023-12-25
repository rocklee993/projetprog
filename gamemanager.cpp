#include "gamemanager.h"
#include <windows.h>
gamemanager::gamemanager(player& player, ruins& ruins)
:
    d_player{player},d_ruins{ruins},d_monsters{}
{

}

void gamemanager::addMonster(std::unique_ptr<monster> monster) {
     d_monsters.push_back(std::move(monster));
}


void gamemanager::gameover() {

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
    int newX = m->getX();
    int newY = m->getY();


 }}
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
        d_player.showstats(cout);


}
void gamemanager::startGame() {

    bool gameIsEnded = false;
   while (!gameIsEnded) {
    d_ruins.initializeRuins(d_player, d_monsters);
    d_ruins.render();
    playerTurn();
    monsterTurn();
}
}
void gamemanager::win() {

}



