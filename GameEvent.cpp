//
// Created by wojciech admin on 01.09.2022.
//

#include "GameEvent.h"

bool GameEvent::IsReleased() {


    return !sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool GameEvent::LeftClicked() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool GameEvent::RightClicked() {
    return  sf::Mouse::isButtonPressed(sf::Mouse::Right);
}
