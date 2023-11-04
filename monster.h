#ifndef MONSTER_H
#define MONSTER_H
#include <memory>
#include <vector>
#include "character.h"


class monster : public character
{
    public:
        monster(int x,int y);
        virtual ~monster();
        void addmonster(monster& m);
        std::vector<std::unique_ptr<monster>> monsters;


    protected:

    private:
        static constexpr bool d_isPlayer = false;


};

#endif // MONSTER_H
