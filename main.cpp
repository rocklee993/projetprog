#include <iostream>
#include <vector>
#include "ruins.h"
#include "character.h"
#include "monsterBlind.h"
#include "monsterSmart.h"
#include "player.h"
#include <windows.h>
#include"gamemanager.h"
using namespace std;

// Function to display available directions and get user input


// monster see
/*void handleMonsterMovement(ruins& r, player& p, monster& m)
{
    int playerX = p.getX();
    int playerY = p.getY();

    int monsterX = m.getX();
    int monsterY = m.getY();

    int dx = 0, dy = 0;

    // Calculate AI logic to move the monster towards the player
    // For example, you can use simple logic here to chase the player
    if (playerX < monsterX) {
        dx = -1;
    } else if (playerX > monsterX) {
        dx = 1;
    }

    if (playerY < monsterY) {
        dy = -1;
    } else if (playerY > monsterY) {
        dy = 1;
    }

    // Check if the new monster position is valid
    if (!r.isWall(monsterX + dx, monsterY + dy)) {
        m.move(dx, dy);
    }
} */

/*void handleMovement(ruins& r, player& p,monster& m, vector<pair<int, int>>& coinPositions, int dx, int dy)
{
    bool invalidMove = false;

    if (r.isTreasure(p.getX() + dx, p.getY() + dy))
    {
        exit(0);
    }

    if (r.isWall(p.getX() + dx, p.getY() + dy))
    {
        invalidMove = true;



    }

    // Check for coin collection
    for (auto it = coinPositions.begin(); it != coinPositions.end(); )
    {
        if (p.getX() + dx == it->first && p.getY() + dy == it->second)
        {
            p.addbourse();
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

    if (!invalidMove)
    {
        p.showstats(cout);
        p.move(dx, dy);
        handleMonsterMovement(r, p, m);


        r.initializeRuins(p, m);
        r.render();

    }
    else
    {
        cout << "Can't move into a wall! Choose a different direction." << endl;
    }
} */

int main()
{
    ruins r(24, 10);
    player play(8,5,100.0,100.0,true,'p');
   // monsters.push_back(std::make_unique<monster>(1, 1, 10, 10, false, 'm', 20));
    gamemanager gm(play,r);
    gm.addMonster(std::make_unique<monsterBlind>(1, 1, 10, 10, false, 'm', 0.20));
    gm.addMonster(std::make_unique<monsterBlind>(1, 2, 10, 10, false, 'm', 0.20));
     gm.addMonster(std::make_unique<monsterSmart>(1, 3, 10, 10, false, 'w', 0.20));
    gm.startGame();
    //int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite

    vector<pair<int, int>> coinPositions = r.getCoinPositions();






}
