//
// Created by wojciech admin on 01.09.2022.
//

#ifndef SFMLTEST_GAMEEVENT_H
#define SFMLTEST_GAMEEVENT_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class GameEvent {
private:
public:

    static bool IsReleased();
    static bool RightClicked();
    static bool LeftClicked();

};


#endif //SFMLTEST_GAMEEVENT_H
