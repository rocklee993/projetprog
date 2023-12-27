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

 if(d_ruins.isWall(x, y))
    {
  // For debugging purposes
        std::cout << "there is a wall in : (" << x << ", " << y << ")" << std::endl;

    return true;
    };
 return false;

}

void gamemanager::monsterTurn(){




for (auto& m : d_monsters)
    {

        if(m->getX() > d_ruins.width())
        {
            if(checkWall(m->getX(), m->getY()))
            {
                m->turnRigth();
                m->chooseDirection();
            }
            else
            {
                m->turnLeft();
                m->chooseDirection();
            }

        }
        if(m->getX() == 0)
        {
            if(checkWall(m->getX(), m->getY()))
            {
                m->turnLeft();
                m->chooseDirection();
            }
            else
            {
                m->turnRigth();
                m->chooseDirection();
            }

        }

//    if(checkWall(m->getX(), m->getY()))
//        m->chooseDirection();

    }
}
void gamemanager::playerTurn() {

    d_player.chooseDirection();
    monsterTurn();


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



