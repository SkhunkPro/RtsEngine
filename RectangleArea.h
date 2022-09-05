//
// Created by wojciech admin on 29.08.2022.
//

#ifndef SFMLTEST_RECTANGLEAREA_H
#define SFMLTEST_RECTANGLEAREA_H
#include <utility>
#include <iostream>
#include "SFML/Graphics.hpp"


class RectangleArea {
private:
    int X;
    int Y;
    int width;
    int height;
    sf::IntRect getIntRect() const;

public:
    RectangleArea(int,int,int,int);
    RectangleArea();
    bool Intersects(RectangleArea) const;
    bool Contains(std::pair<int,int>) const;

    void setSize(int,int);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
};


#endif //SFMLTEST_RECTANGLEAREA_H
