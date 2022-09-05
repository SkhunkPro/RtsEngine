#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

int main()
{
    Game game;


    while(game.IsWindowOpen()) {

        game.Render();
        game.CloseWindow();
    }

    return 0;
}