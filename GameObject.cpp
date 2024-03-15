#include <iostream>

#include "GameObject.h"

GameObject::GameObject(){
    level = 0;
    locationX = 0;
    locationY = 0;
    displayCharacter = '\0';
}

GameObject::GameObject(int level, int locationX, int locationY){
    level = level;
    locationX = locationX;
    locationY = locationY;
    displayCharacter = '\0';
}

GameObject::~GameObject(){
    std::cout << "object deleted" << std::endl;
}

char GameObject::getDisplayCharacter(){
    return displayCharacter;
}