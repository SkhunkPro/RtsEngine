//
// Created by wojciech admin on 02.09.2022.
//

#ifndef SFMLTEST_ACTIONREQUEST_H
#define SFMLTEST_ACTIONREQUEST_H
#include "Player.h"
#include "GameEntity.h"
#include "ActionType.h"

#include <vector>

class ActionRequest {
private:
    ActionType actionType;
    int X,Y;
    Player * player;
    GameEntity* actionObject;
    std::vector<GameEntity*>* otherEntities;

public:
    ActionRequest(Player* ,GameEntity*,int,int);
    void setOtherEntities(std::vector<GameEntity *> *otherEntities);
    void CalculateActionType();


    GameEntity *getActionObject() const;
    std::pair<int,int> getXY();


    ActionType getActionType() const;

};


#endif //SFMLTEST_ACTIONREQUEST_H
