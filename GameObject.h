#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

class GameObject{ 
    public: //need default constructor? implement interact method?
        GameObject(); //default constructor
        GameObject(int level, int locationX, int locationY); //constructor with location of object
        ~GameObject(); //destructor
        //int getIsEmpty();

        //getter methods
        char getDisplayCharacter(); //returns displayCharacter
        int getLevel(); //returns level
        int getLocationX(); //returns locationX
        int getLocationY(); //returns locationY
        std::string getObjectName(); //returns object name

        //setter methods
        void setDisplayCharacter(char c); //sets displayCharacter

    protected: 
        int level; //what level the object is in
        int locationX; //x location of the object
        int locationY; //y location of the object
        //int isEmpty; 
        char displayCharacter; //the display character of the object
        std::string objectName; //the name of the object name
};

#endif
