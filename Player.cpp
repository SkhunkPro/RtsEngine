//
// Created by wojciech admin on 01.09.2022.
//

#include "Player.h"
Player::Player(std::vector<GameEntity*>* entities) {
    playerEntities=entities;
    IsPicking= false;
    pickedArea=RectangleArea();


}
void Player::pickArea(int x ,int y) {
    if(GameEvent::LeftClicked()&&!IsPicking){

        IsPicking=true;
        pickedArea= RectangleArea(x,y,0,0);
    }
    if(IsPicking){

        pickedArea.setSize(x-pickedArea.getX(),y-pickedArea.getY());

    }
    if(GameEvent::IsReleased()){

        IsPicking=false;
        pickedArea=RectangleArea();
    }

}
void Player::pickArea(std::pair<int,int> point) {


    if(GameEvent::LeftClicked()&&!IsPicking){

        IsPicking=true;
        pickedArea= RectangleArea(point.first,point.second,0,0);

    }
    if(IsPicking){

        pickedArea.setSize(point.first-pickedArea.getX(),point.second-pickedArea.getY());


    }
    if(GameEvent::IsReleased()){

        IsPicking=false;
        pickedArea=RectangleArea();
    }

}

void Player::pickEntities() {

    for(auto&& it:*playerEntities){

        if(it->getEntityArea().Intersects(pickedArea)){
            it->setIsPicked(true);


        }else{
            if(GameEvent::LeftClicked()){
                it->setIsPicked(false);
            }


        }
    }
}

RectangleArea Player::getPickedArea() {
    return  pickedArea;
}

std::vector<GameEntity *> *Player::getPlayerEntities() const {
    return playerEntities;
}
