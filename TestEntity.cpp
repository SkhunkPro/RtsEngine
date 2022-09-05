//
// Created by wojciech admin on 29.08.2022.
//

#include "TestEntity.h"

TestEntity::TestEntity(int x,int y,int msx,int msy,sf::RenderWindow* window) : GameEntity(x,y,msx,msy,window,22,22){
    texture->loadFromFile("Assets/creeper.png");
    this->setTexture(texture);
}
