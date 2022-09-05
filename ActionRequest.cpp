//
// Created by wojciech admin on 02.09.2022.
//

#include "ActionRequest.h"

ActionRequest::ActionRequest(Player * player, GameEntity * gameEntity, int x, int y) :player(player),actionObject(gameEntity),X(x),Y(y){}

void ActionRequest::setOtherEntities(std::vector<GameEntity *> *otherEntities) {
    ActionRequest::otherEntities = otherEntities;
}

void ActionRequest::CalculateActionType() {
    for(auto&& it:*otherEntities){
        if(it->getEntityArea().Contains(std::pair<int,int>(X,Y))){
            //kolory entities i graczy
            actionType=ActionType::Move;

        }
    }
    actionType=ActionType::Move;

}

ActionType ActionRequest::getActionType() const {
    return actionType;
}

GameEntity *ActionRequest::getActionObject() const {
    return actionObject;
}

std::pair<int, int> ActionRequest::getXY() {
    return std::pair<int,int>(X,Y);
}

