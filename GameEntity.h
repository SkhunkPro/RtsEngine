//
// Created by wojciech admin on 29.08.2022.
//
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "RectangleArea.h"
#include "EntityState.h"
#include "ActionType.h"




#ifndef SFMLTEST_GAMEENTITY_H
#define SFMLTEST_GAMEENTITY_H


class GameEntity {
protected:
    sf::RenderWindow* gameWindow;
    sf::Sprite* sprite;
    sf::Texture* texture;
    RectangleArea entityArea;
    bool IsPicked;
    float X,Y;
    float sizeX , sizeY;
    int mapSizeX,mapSizeY;
    EntityState entityState;
    std::pair<float,float> Objective;


public:
    const RectangleArea &getEntityArea() const;

    GameEntity(int,int,int,int,sf::RenderWindow*,int,int);
    void draw();
    void UpdateScreenPosition(float,float);
    void UpdateArea();
    void setTexture(sf::Texture*);
    std::pair<int,int> getPos();
    int getX();
    int getY();
    virtual void move();
    virtual void animate();
    virtual void setObjective(std::pair<float,float>);

    void setEntityState(ActionType);

    void setIsPicked(bool);

    bool isPicked() const;

    EntityState getEntityState() const;


};


#endif //SFMLTEST_GAMEENTITY_H
