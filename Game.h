//
// Created by wojciech admin on 29.08.2022.
//

#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H
#include "GameMap.h"
#include <vector>
#include "TestEntity.h"
#include <iostream>


class Game {
private:
    GameMap* gameMap;
    sf::RenderWindow* gameWindow;
    sf::Cursor* cursor;
public:
    Game();
    void Render();
    bool IsWindowOpen();
    void CloseWindow();



};


#endif //SFMLTEST_GAME_H
