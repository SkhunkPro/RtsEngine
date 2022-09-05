//
// Created by wojciech admin on 29.08.2022.
//
#include "GameEntity.h"
#include "Camera.h"
#include <vector>
#include "MovableEntity.h"
#include "TestEntity.h"
#include "MapFilling.h"


#ifndef SFMLTEST_GAMEMAP_H
#define SFMLTEST_GAMEMAP_H


class GameMap {
private:

    std::vector<GameEntity*>* GameEntities;
    sf::RenderWindow* window;
    std::vector<Player*> players;

    Camera* camera;


    int sizeX,sizeY;
public:
    GameMap(sf::RenderWindow*);
    void UpdateRequests();
    void UpdateEntities();
    void UpdateCamera();
    void DrawEntities();

};


#endif //SFMLTEST_GAMEMAP_H
