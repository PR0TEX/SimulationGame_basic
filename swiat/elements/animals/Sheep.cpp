#include <iostream>
#include "Sheep.hpp"
#include "World.hpp"
#include "Empty.hpp"

Sheep::Sheep(){}

Sheep::Sheep(World *world,const CORDS position){
    this->world=world;
    this->position=position;
    this->initiative=4;
    this->power=4;
    this->age=0;
}
void Sheep::meet(Organism *opponent){
    DIRECTION turn = chooseTurn(opponent->getPosition());
    if(dynamic_cast<Empty*>(neight(turn, 1))){
        switch(turn) {
            case UP:
                if(position.y > 0) world->addElement(new Sheep(world,{position.y-1,position.x}));
                break;
            case DOWN:
                if(position.y < world->getHeight()-1) world->addElement(new Sheep(world,{position.y+1,position.x}));
                break;
            case LEFT:
                if(position.x > 0) world->addElement(new Sheep(world,{position.y,position.x-1}));
                break;
            case RIGHT:
                if(position.x < world->getWidth()-1) world->addElement(new Sheep(world,{position.y,position.x+1}));
                break;
        }
    }
}
const void Sheep::print() { std::cout<<SHEEP; }
const char Sheep::getName() { return SHEEP; }

Sheep::~Sheep() {
    std::string info;
    info+=this->getName();
    info+=" killed";
    world->fit(info);
}
