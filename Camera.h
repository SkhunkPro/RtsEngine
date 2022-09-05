//
// Created by wojciech admin on 29.08.2022.
//
#include <vector>
#include "GameEntity.h"
#include "RectangleArea.h"
#include <iostream>
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "ActionRequest.h"
#ifndef SFMLTEST_CAMERA_H
#define SFMLTEST_CAMERA_H



class Camera {
private:
    std::vector<GameEntity*>* GameEntities;
    sf::RenderWindow* CameraWindow;
    RectangleArea rectangleArea;
    Player* player;
    sf::RectangleShape* pickedAreaDisplay;

    float X,Y;
    int sizeX,sizeY;
    int MapSizeX,MapSizeY;
    float velocityX ,velocityY;

    void CalculateScreenPosition(GameEntity*);

public:
    Camera(sf::RenderWindow*,int,int,Player*);
    void update(std::vector<GameEntity*>*);
    void draw();
    void move();
    void pickEntities();
    void displayPickArea();
    std::pair<int,int> getPosOnMap(int,int);
    std::pair<int,int> getCameraPos();
    std::vector<ActionRequest*> getActionRequestFromCamera();



};


#endif //SFMLTEST_CAMERA_H
