//
// Created by wojciech admin on 01.09.2022.
//

#ifndef SFMLTEST_PLAYER_H
#define SFMLTEST_PLAYER_H
#include "GameEntity.h"
#include <vector>
#include <iostream>
#include "PlayerColour.h"
#include "RectangleArea.h"
#include "GameEvent.h"


class Player {
private:
    std::vector<GameEntity*>* playerEntities;
    PlayerColour playerColour;
    RectangleArea pickedArea;
    bool IsPicking;
public:
    Player(std::vector<GameEntity*>*);
    void pickArea(int ,int );
    void pickArea(std::pair<int,int>);
    void pickEntities();

    std::vector<GameEntity *> *getPlayerEntities() const;

    RectangleArea getPickedArea();



};


#endif //SFMLTEST_PLAYER_H
