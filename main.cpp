#include <iostream>
#include <vector>
#include "ruins.h"
#include "character.h"
#include "monster.h"
#include "player.h"
#include <windows.h>

using namespace std;

// Function to display available directions and get user input
char getDirection()
{
    cout << "What will be your next move? (1/2/3/4/5/6/7/8/9): " << endl;
    char direction;
    cin >> direction;
    return direction;
}
void handleMonsterMovement(ruins& r, player& p, monster& m)
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
}

void handleMovement(ruins& r, player& p,monster& m, vector<pair<int, int>>& coinPositions, int dx, int dy)
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
}

int main()
{
    ruins r(24, 10);
    player play(8,5,100.0,100.0,true,'p');

    monster m(1, 1);
    r.initializeRuins(p, m);
    r.render();
    vector<pair<int, int>> coinPositions = r.getCoinPositions();

    while (true)
    {
        char direction = getDirection();
        int dx = 0, dy = 0;

        switch (direction)
        {
        case '2':
            dy = -1;
            break;
        case '4':
            dx = -1;
            break;
        case '8':
            dy = 1;
            break;
        case '6':
            dx = 1;
            break;
        case '1':
            dx = -1;
            dy = -1;
            break;
        case '3':
            dx = 1;
            dy = -1;
            break;
        case '7':
            dx = -1;
            dy = 1;
            break;
        case '9':
            dx = 1;
            dy = 1;
            break;
        case '5':
            cout << "Player chose not to move" << endl;
            break;
        default:
            cout << "Invalid direction. Please use 1/2/3/4/5/6/7/8/9." << endl;
            continue;
        }

        handleMovement(r, p,m, coinPositions, dx, dy);
    }

    return 0;

    // fouad
}
