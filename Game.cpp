//
// Created by wojciech admin on 29.08.2022.
//

#include "Game.h"
#include  <cstdlib>
Game::Game() {
    cursor = new sf::Cursor();
    sf::Image image;
    image.loadFromFile("Assets/testimage.png");
    cursor->loadFromPixels(image.getPixelsPtr(),sf::Vector2u(20,20),sf::Vector2u(0,0));
    gameWindow = new sf::RenderWindow(sf::VideoMode(1900,1000),"Game Engine Test");
    gameWindow->setMouseCursor(*cursor);
    gameMap = new GameMap(gameWindow);

}

void Game::Render() {
    sf::Event event;
    while (gameWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            gameWindow->close();
    }
    gameMap->UpdateCamera();
    gameMap->UpdateEntities();
    gameMap->UpdateRequests();
    gameWindow->clear(sf::Color::Black);
    gameMap->DrawEntities();
    gameWindow->display();

}

bool Game::IsWindowOpen() {
    return gameWindow->isOpen();
}

void Game::CloseWindow() {
    sf::Event event;
    if (event.type == sf::Event::Closed)
        gameWindow->close();
}


