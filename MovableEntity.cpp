//
// Created by wojciech admin on 31.08.2022.
//

#include "MovableEntity.h"



MovableEntity::MovableEntity(int x, int y,int msx,int msy,sf::RenderWindow* window) : GameEntity(x, y,msx,msy,window,10,10) {
    texture->loadFromFile("Assets/amongus.png");
    this->setTexture(texture);
    Velocity= float(rand() % 1000)/1000.0f;




}

void MovableEntity::setObjective(std::pair<float, float> objective) {
    Objective=std::pair<int,int>(objective.first-sizeX*5,objective.second-sizeY*5);
    calculateDirection();



}

void MovableEntity::calculateDirection() {
    float deltaX = Objective.first - X;
    float deltaY = Objective.second -Y;
    direction = std::atan2(deltaY,deltaX);
    moveObjectiveArea = RectangleArea(Objective.first-2,Objective.second-2,4,4);

}




void MovableEntity::move() {
    if (moveObjectiveArea.Contains(std::pair<int,int>(X,Y))) {
        entityState = NonActive;

    }

    if (entityState == Moving) {
        calculateDirection();
        X+=Velocity*std::cos(direction);
        Y+=Velocity*std::sin(direction);

    }

}





