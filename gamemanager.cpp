#include "gamemanager.h"
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



bool  gamemanager::checkWall(character& c,int x , int y) const {

 if (d_ruins.isWall(x, y))
    {
        return true;

    }
    return false;
}

void gamemanager::monsterTurn(){


 for (auto& m : d_monsters) {
    m->chooseDirection();
    std::vector<int> nextDirection = m.getNextDirection();
    nextDirection = m.getNextDirection();
    int newX = m->getX() + m->nextDirection[0];
    int newY = m->getY() + m->nextDirection[1];

    while (checkWall(newX, newY)) {
        m->chooseDirection();
             nextDirection = m.getNextDirection();
        newX = m->getX() + m->nextDirection[0];
        newY = m->getY() + m->nextDirection[1];
    }

    m->move();
}
void gamemanager::playerTurn() {

    d_player.chooseDirection();
    int newX = c.getX() + c.d_nextDirection[0];
    int newY = c.getX() + c.d_nextDirection[1];
    while(checkWall(newX,newY)) {

         std::cout << "Can't move into a wall! Choose a different direction." << endl;
         d_player.chooseDirection();
          newX = c.getX() + c.d_nextDirection[0];
    newY= c.getX() + c.d_nextDirection[1];
    }

    if (d_ruins.isTreasure(newX,newY))
    {
        exit(0);
    }

      for (auto it = coinPositions.begin(); it != coinPositions.end(); )
    {
        if (newX == it->first && newY == it->second)
        {
            d_player.addbourse();
            cout<<"!!!!!!!!!!"<<endl;
            Sleep(1000);
            cout << "You hit the jackpot! You collected a coin." << endl;
            it = coinPositions.erase(it);
        }
        else
        {
            ++it;
        }
    }
        d_player.showstats(cout);
        d_player.move();


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



