//
// Created by wojciech admin on 30.08.2022.
//
#include "RectangleArea.h"

RectangleArea::RectangleArea(int x, int y, int w, int h):X(x) ,Y(y),width(w),height(h){};
RectangleArea::RectangleArea():X(0) ,Y(0),width(0),height(0){};

sf::IntRect RectangleArea::getIntRect() const{
    if(width>0&&height<0){
        return sf::IntRect(X,Y+height,width,-height);

    }
    if(width<0&&height<0){
        return sf::IntRect(X+width,Y+height,-width,-height);

    }
    if(width<0&&height>0){
        return sf::IntRect(X+width,Y,-width,height);
    }
    return sf::IntRect (X,Y,width,height);


}
bool RectangleArea::Contains(std::pair<int, int> point) const {
    return point.first>X&&point.first<X+width&&point.second>Y&&point.second<Y+height||
           point.first<X&&point.first>X+width&&point.second<Y&&point.second>Y+height;



}


bool RectangleArea::Intersects(RectangleArea r) const{
    return r.getIntRect().intersects(getIntRect());


}

void RectangleArea::setSize(int w, int h) {
    width=w;
    height=h;

}

int RectangleArea::getX() const {
    return X;
}

int RectangleArea::getY() const {
    return Y;
}

int RectangleArea::getWidth() const {
    return width;
}

int RectangleArea::getHeight() const {
    return height;
}
