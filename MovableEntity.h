//
// Created by wojciech admin on 31.08.2022.
//

#ifndef SFMLTEST_MOVABLEENTITY_H
#define SFMLTEST_MOVABLEENTITY_H
#include "GameEntity.h"
#include <iostream>
#include <cmath>




class MovableEntity :public GameEntity{
private:
    float Velocity;
    float direction;
    RectangleArea moveObjectiveArea;
    void calculateDirection();

public:
    MovableEntity(int,int,int,int,sf::RenderWindow*);
    void setObjective(std::pair<float,float>);

    void move();

};


#endif //SFMLTEST_MOVABLEENTITY_H
