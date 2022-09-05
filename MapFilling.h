//
// Created by wojciech admin on 02.09.2022.
//

#ifndef SFMLTEST_MAPFILLING_H
#define SFMLTEST_MAPFILLING_H
#include "GameEntity.h"


class MapFilling: public GameEntity{
private:
    sf::Image* image;
public:
    MapFilling(int,int,sf::RenderWindow*);

};


#endif //SFMLTEST_MAPFILLING_H
