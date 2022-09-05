//
// Created by wojciech admin on 29.08.2022.
//

#include "GameEntity.h"
#include <iostream>


GameEntity::GameEntity(int x, int y,int msX,int msY,sf::RenderWindow* window,int sX,int sY):X(x),Y(y),mapSizeY(msX),mapSizeX(msY),sizeX(sX),sizeY(sY){
    IsPicked=false;
    gameWindow = window;
    sprite=new sf::Sprite();
    texture= new sf::Texture();
    sprite->setTextureRect(sf::IntRect(0,0,sizeX*10,sizeY*10));
    entityState=NonActive;
    entityArea =RectangleArea(x,y,sizeX*10,sizeY*10);
}

void GameEntity::move() {



}


void GameEntity::draw() {

    gameWindow->draw(*sprite);

}

void GameEntity::UpdateScreenPosition(float x,float y) {
    sprite->setPosition(x,y);
}

void GameEntity::UpdateArea()  {
    entityArea =RectangleArea(X,Y,sizeX*10,sizeY*10);
}

std::pair<int, int> GameEntity::getPos() {
    return  std::pair<int,int>(X,Y);
}

void GameEntity::setTexture(sf::Texture *texture) {
    sprite->setTexture(*texture);
}

int GameEntity::getX() {
    return X;
}
int  GameEntity::getY() {
    return Y;
}

void GameEntity::setIsPicked(bool isPicked) {
    IsPicked = isPicked;
}

void GameEntity::animate() {
    if(IsPicked){
        sprite->setColor(sf::Color(190,190,190));

    }
    else{
        sprite->setColor(sf::Color::White);
    }
}

bool GameEntity::isPicked() const {
    return IsPicked;
}

const RectangleArea &GameEntity::getEntityArea() const {
    return entityArea;
}

void GameEntity::setObjective(std::pair<float, float> objective) {
    Objective=objective;
}

void GameEntity::setEntityState(ActionType actionType) {
    if(actionType==Move){
        entityState=Moving;
    }
}

EntityState GameEntity::getEntityState() const {
    return entityState;
}


