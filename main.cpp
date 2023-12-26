#include <iostream>

using namespace std;

int main()
{
<<<<<<< Updated upstream
    cout << "Hello world!" << endl;
    return 0;
=======
    ruins r(24, 10);
    player play(8,5,100.0,100.0,true,'p');
   // monsters.push_back(std::make_unique<monster>(1, 1, 10, 10, false, 'm', 20));
    gamemanager gm(play,r);
    gm.addMonster(std::make_unique<monsterBlind>(1, 1, 10, 10, false, 'm', 0.20));
    gm.addMonster(std::make_unique<monsterBlind>(1, 2, 10, 10, false, 'm', 0.20));
     gm.addMonster(std::make_unique<monsterSmart>(19, 9, 10, 10, false, 'w', 0.20));
    gm.startGame();
    //int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite

    vector<pair<int, int>> coinPositions = r.getCoinPositions();






>>>>>>> Stashed changes
}
