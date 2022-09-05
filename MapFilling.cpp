//
// Created by wojciech admin on 02.09.2022.
//

#include "MapFilling.h"
MapFilling::MapFilling(int msX,int msY,sf::RenderWindow* window)
        : GameEntity(0, 0, msX, msY, window,200,200) {
    image =   new sf::Image();
    image->create(msX,msY,sf::Color::White);
    texture->loadFromImage(*image);
    sprite->setTexture(*texture);



}
