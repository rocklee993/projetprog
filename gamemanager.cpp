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
        m->chooseDirection();

  std::vector<int>  nextDirection = m->getNextDirection();
    int newX = m->getX() + nextDirection[0];
    int newY = m->getY() + nextDirection[1];

    while (checkWall(newX, newY)) {
        m->chooseDirection();
             nextDirection = m->getNextDirection();
        newX = m->getX() + nextDirection[0];
        newY = m->getY() + nextDirection[1];
    }

    m->move();
}
}
void gamemanager::playerTurn() {

 int newX, newY;
do {
    d_player.chooseDirection();
    std::vector<int> nextDirection = d_player.getNextDirection();
    newX = d_player.getX() + nextDirection[0];
    newY = d_player.getY() + nextDirection[1];

    // For debugging purposes
  //  std::cout << "Player Position: (" << d_player.getX() << ", " << d_player.getY() << ")" << std::endl;
   // std::cout << "Next Position: (" << newX << ", " << newY << ")" << std::endl;

} while (checkWall(newX, newY));

 std::cout << "non wall" << std::endl;
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

        d_player.move();


        std::cout << "Next Position: (" << newX << ", " << newY << ")" << std::endl;
            std::cout << "Player Position: (" << d_player.getX() << ", " << d_player.getY() << ")" << std::endl;

               std::cout << d_player.getX() << "  " << d_player.getY();



}
void gamemanager::startGame() {

    bool gameIsEnded = false;
    while (!gameIsEnded) {
    d_ruins.initializeRuins(d_player, d_monsters);
    d_ruins.render();
    playerTurn();
   // monsterTurn();
}
}
void gamemanager::win() {

}



