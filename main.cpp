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

int main()
{
    ruins r(24, 10);
    player play(8,5,10,20,true,'p');
    gamemanager gm(play,r);
    gm.addMonster(std::make_unique<monsterBlind>(1, 1, 10, 9, false, 'm', 0.3));
    gm.addMonster(std::make_unique<monsterBlind>(1, 2, 10, 9, false, 'm', 0.6));
     gm.addMonster(std::make_unique<monsterSmart>(1, 3, 10, 9, false, 'w', 0.2));
    gm.startGame();
    vector<pair<int, int>> coinPositions = r.getCoinPositions();

}
