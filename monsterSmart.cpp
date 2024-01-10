#include "monsterSmart.h"
#include <cmath>
monsterSmart::monsterSmart(int x,int y,int health,double pointForce,bool player,char symbol,int pourcentageHabilite):
    monster{x,y,health,pointForce,false,symbol,pourcentageHabilite}
{
    //ctor
}
void monsterSmart::theShortestRoadToPlayer(int targetX,int targetY,std::vector<std::pair<int, int>>& wallPositions){


    // Vérifier si la case cible est libre

        // Si la case cible est occupée, essayer de trouver une direction libre
        double minDistance = INT_MAX;
        int bestX = 0;
        int bestY = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;  // Ne pas rester sur place
                }
                int newX = getX() + dx;
                int newY = getY() + dy;
                d_nextDirection[0] = dx;
                d_nextDirection[1] = dy;

                if (!checkWall(wallPositions)) {
                    // Calculer la distance euclidienne jusqu'à la cible
                    double distance = std::sqrt(std::pow(newX - targetX, 2) + std::pow(newY - targetY, 2));

                    // Mettre à jour la meilleure direction si la distance est plus petite
                    if (distance < minDistance) {
                        minDistance = distance;
                        bestX = dx;
                        bestY = dy;
                    }
                }
            }
        }

        // Mettre à jour la direction avec la meilleure option
        d_nextDirection[0] = bestX;
        d_nextDirection[1] = bestY;

        //move();

}
void monsterSmart::chooseDirection(std::vector<std::pair<int, int>>& wallPositions,character* character) {

 // Calculer la direction du joueur

    int directionX = character->getX() - getX();
    int directionY = character->getY() - getY();

    // Coordonnées cibles
    int targetX = getX() + (directionX > 0) - (directionX < 0);
    int targetY = getY() + (directionY > 0) - (directionY < 0);

    // Calculer la distance euclidienne jusqu'à la cible
    double distance = std::sqrt(std::pow(targetX - getX(), 2) + std::pow(targetY - getY(), 2));

    // Vérifier si la distance est supérieure à 8
    if (distance < 8) {
        // Utiliser A* si la distance est supérieure à 8
        theShortestRoadToPlayer(targetX,targetY,wallPositions);


    } else {
        // Sinon, utiliser une direction aléatoire
       monster::getRandomDirection(wallPositions);
    }
}

