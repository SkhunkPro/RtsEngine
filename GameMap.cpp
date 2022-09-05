//
// Created by wojciech admin on 29.08.2022.

//

#include "GameMap.h"



GameMap::GameMap(sf::RenderWindow* window){
    sizeY=2000;
    sizeX=2000;


    this->window = window;
    std::vector<GameEntity*> *test;
    std::vector<GameEntity*> *test1;
    test = new std::vector<GameEntity*>;
    test1 = new std::vector<GameEntity *>;
    test->push_back(new MapFilling(sizeX,sizeY,window));
    for (int i = 0; i<10; i++) {
        test->push_back(new TestEntity( i*300, i*300,sizeX,sizeY,window));
        test1->push_back(new MovableEntity(i*150,0,sizeX,sizeY,window));
    }

    players.push_back(new Player(test1));
    GameEntities = test;

    camera = new Camera(window,sizeX,sizeY,players[0]);

}

void GameMap::UpdateRequests() {

    for(auto&& it:camera->getActionRequestFromCamera()){

        it->setOtherEntities(GameEntities);
        it->CalculateActionType();

        if(it->getActionType()==Move){
            it->getActionObject()->setObjective(it->getXY());
            it->getActionObject()->setEntityState(it->getActionType());

        }

    }

}

void GameMap::UpdateEntities() { // game entittes nie zawiera players entites dlatego sie nie rusza
    for(auto&& it:*GameEntities){
        it->UpdateArea();
        if(it->getEntityState()==Moving){

            it->move();

        }
    }
    for(auto&& it:players){
        for(auto&& jt:*it->getPlayerEntities()){
            jt->UpdateArea();
            if(jt->getEntityState()==Moving){

                jt->move();

            }
        }
    }
}

void GameMap::UpdateCamera() {
    camera->move();
    camera->update(GameEntities);
    camera->pickEntities();

}
void GameMap::DrawEntities() {

    camera->draw();
    camera->displayPickArea();


}
