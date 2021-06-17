#include <iostream>
#include "Wolf.hpp"
#include "Empty.hpp"
#include "World.hpp"

Wolf::Wolf(){}

Wolf::Wolf(World *world,const CORDS position){
    this->world=world;
    this->position=position;
    this->initiative=5;
    this->power=9;
    this->age=0;
}
void Wolf::meet(Organism *opponent){
    std::string info="";
    DIRECTION turn = chooseTurn(opponent->getPosition());
    if(dynamic_cast<Empty*>(neight(turn, 1))){
        int tempY=position.y;
        int tempX=position.x;
        do{
        switch(turn) {
            case UP:
                if(position.y > 0) world->addElement(new Wolf(world,{position.y-1,position.x}));
                break;
            case DOWN:
                if(position.y < world->getHeight()-1) world->addElement(new Wolf(world,{position.y+1,position.x}));
                break;
            case LEFT:
                if(position.x > 0) world->addElement(new Wolf(world,{position.y,position.x-1}));
                break;
            case RIGHT:
                if(position.x < world->getWidth()-1) world->addElement(new Wolf(world,{position.y,position.x+1}));
                break;
        }
            //srand(time(NULL));
            turn = (DIRECTION) (rand() % 4);
        }while(position.y == tempY && position.x == tempX);
        info+=POSIT;
        world->fit(info);
    }
}
const void Wolf::print(){ std::cout<<WOLF; }
const char Wolf::getName() { return WOLF; }

Wolf::~Wolf() {
    std::string info;
    info+=this->getName();
    info+=" killed";
    world->fit(info);
}
