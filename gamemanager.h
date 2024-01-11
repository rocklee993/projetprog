#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "ruins.h"
#include"player.h"
#include"monster.h"

class gamemanager
{
    public: gamemanager(player& player, ruins& ruins);
         void addMonster(std::unique_ptr<monster> monster);
        void startGame();
        void playerTurn();
        void monsterTurn();
        void gameover();
        void win();
        bool checkWall(int x , int y) const;


    private:
        player d_player;
      std::vector<std::unique_ptr<monster>> d_monsters;
        ruins d_ruins;
        bool d_gameEnded;
        void instruction();

};

#endif // GAMEMANAGER_H
