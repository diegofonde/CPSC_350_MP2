#include <iostream>

#include "GameObject.h"

GameObject::GameObject(){

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