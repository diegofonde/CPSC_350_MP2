#include <iostream>

#include "GameObject.h"

GameObject::GameObject(){
    level = -1;
    locationX = -1;
    locationY = -1;
}

GameObject::GameObject(int level, int locationX, int locationY){
    level = level;
    locationX = locationX;
    locationY = locationY;
}

GameObject::~GameObject(){
    std::cout << "object deleted" << std::endl;
}

char GameObject::getDisplayCharacter(){
    return displayCharacter;
}

int GameObject::getLevel(){
    return level;
}

int GameObject::getLocationX(){
    return locationX;
}

int GameObject::getLocationY(){
    return locationY;
}