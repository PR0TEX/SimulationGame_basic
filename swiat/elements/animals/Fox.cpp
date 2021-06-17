#include "Fox.hpp"

Fox::Fox(){}

Fox::Fox(World *world,const CORDS position){
    this->world=world;
    this->position=position;
    this->initiative=7;
    this->power=3;
    this->age=0;
}
void Fox::action(){
    DIRECTION turn;
    int tempX=getPosition().x;
    int tempY=getPosition().y;
    turn = (DIRECTION) (rand()%4);
    if(dynamic_cast<Empty*>(neight(turn, 1))) move(turn);
    else {
        if(neight(turn,1)){
            if(neight(turn, 1)->getPower() <= this->getPower()){
                neight(turn, 1)->collision(this);
                if(neight(turn, 1)) move(turn);
            }
    }
        if(tempX != getPosition().x || tempY != getPosition().y) {
            std::string info="";
            info+=this->getName();
            info+=POS_CH;
            world->fit(info);
            world->world[tempY][tempX]=new Empty();
        }
    }
}
void Fox::meet(Organism *opponent){
    DIRECTION turn = chooseTurn(opponent->getPosition());
    if(dynamic_cast<Empty*>(neight(turn, 1))){
        switch(turn) {
            case UP:
                if(position.y > 0) world->addElement(new Fox(world,{position.y-1,position.x}));
                break;
            case DOWN:
                if(position.y < world->getHeight()-1) world->addElement(new Fox(world,{position.y+1,position.x}));
                break;
            case LEFT:
                if(position.x > 0) world->addElement(new Fox(world,{position.y,position.x-1}));
                break;
            case RIGHT:
                if(position.x < world->getWidth()-1) world->addElement(new Fox(world,{position.y,position.x+1}));
                break;
        }
    }
}
const void Fox::print() { std::cout<<FOX; }
const char Fox::getName() { return FOX; }

Fox::~Fox() {
    std::string info;
    info+=this->getName();
    info+=" killed";
    world->fit(info);
}
