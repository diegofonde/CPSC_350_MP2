#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject{ 
    public: //need default constructor? implement interact method?
        GameObject(); //default constructor
        GameObject(int level, int locationX, int locationY); //constructor with location of object
        ~GameObject(); //destructor
        char getDisplayCharacter(); //returns displayCharacter

    protected: 
        int level; //what level the object is in
        int locationX; //x location of the object
        int locationY; //y location of the object
        char displayCharacter = '\0'; //the display character of the object
};

#endif
