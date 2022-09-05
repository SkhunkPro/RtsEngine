//
// Created by wojciech admin on 29.08.2022.
//

#include "Camera.h"

Camera::Camera(sf::RenderWindow *window,int mapSizeX,int mapSizeY,Player* player1):sizeX(window->getSize().x),sizeY(window->getSize().y),X(0),Y(0),velocityX(0.8f),velocityY(0.8f),MapSizeX(mapSizeX),MapSizeY(mapSizeY){
    player=player1;
    CameraWindow=window;
    GameEntities=new std::vector<GameEntity*>();
    pickedAreaDisplay=new sf::RectangleShape();
    pickedAreaDisplay->setFillColor(sf::Color::Transparent);
    pickedAreaDisplay->setSize(sf::Vector2f(0,0));
    rectangleArea=RectangleArea(X,Y,sizeX,sizeY);

}

void Camera::CalculateScreenPosition(GameEntity* gameEntity) {
    gameEntity->UpdateScreenPosition(gameEntity->getX()-X,gameEntity->getY()-Y);

}
void Camera::update(std::vector<GameEntity*> * Entities) {
    rectangleArea=RectangleArea(X,Y,sizeX,sizeY);
    GameEntities->clear();

    for(auto&& it:*Entities){

        if(true||rectangleArea.Contains(it->getPos())){
            GameEntities->push_back(it);
            CalculateScreenPosition(it);
        }

    }
    for(auto&& it:*player->getPlayerEntities()){
        GameEntities->push_back(it);
        it->animate();
        CalculateScreenPosition(it);
    }
}

void Camera::draw() {
    for(auto&& it:*GameEntities){
        it->draw();

    }
}

void Camera::move() {
    if(sf::Mouse::getPosition(*CameraWindow).y<=0){
        Y-=velocityY;
    }
    if(sf::Mouse::getPosition(*CameraWindow).y>=sizeY){
        Y+=velocityY;
    }
    if(sf::Mouse::getPosition(*CameraWindow).x>=sizeX){
        X+=velocityX;
    }
    if(sf::Mouse::getPosition(*CameraWindow).x<=0) {
        X -= velocityX;
    }


}

 std::pair<int, int> Camera::getPosOnMap(int x,int y) {
    return std::pair<int,int>(X+x,Y+y);

}

std::pair<int, int> Camera::getCameraPos() {
    return std::pair<int,int>(X,Y);
}

void Camera::pickEntities() {
    player->pickEntities();
    player->pickArea(sf::Mouse::getPosition(*CameraWindow).x+X,sf::Mouse::getPosition(*CameraWindow).y+Y);



}

void Camera::displayPickArea() {
    pickedAreaDisplay->setSize(sf::Vector2f (player->getPickedArea().getWidth(),
                                             player->getPickedArea().getHeight()));
    pickedAreaDisplay->setPosition(player->getPickedArea().getX()-X,player->getPickedArea().getY()-Y);
    pickedAreaDisplay->setOutlineColor(sf::Color::Black);
    pickedAreaDisplay->setOutlineThickness(1);
    CameraWindow->draw(*pickedAreaDisplay);

}

std::vector<ActionRequest*> Camera::getActionRequestFromCamera() {
    std::vector<ActionRequest*> result;
    for(auto&& it:*GameEntities){

        if(GameEvent::RightClicked()&&it->isPicked()){

            result.push_back(new ActionRequest(player,it ,sf::Mouse::getPosition(*CameraWindow).x+X,sf::Mouse::getPosition(*CameraWindow).y+Y));
        }
    }

    return result;
}


