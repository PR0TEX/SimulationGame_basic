#include "Dandelion.hpp"

Dandelion::Dandelion() {}

Dandelion::Dandelion(World *world, CORDS position){
    this->world=world;
    this->position=position;
    this->initiative=0;
    this->power=0;
}
void Dandelion::action(){
    if(spread()){
        int attemp=0;
        while(attemp < 3){
            DIRECTION turn = (DIRECTION) (rand() % 4);
            attemp++;
            if(dynamic_cast<Empty*>(neight(turn, 1))) {
                switch(turn) {
                    case UP:
                        if(position.y > 0) world->addElement(new Dandelion(world,{position.y-1,position.x}));
                        break;
                    case DOWN:
                        if(position.y < world->getHeight()-1) world->addElement(new Dandelion(world,{position.y+1,position.x}));
                        break;
                    case LEFT:
                        if(position.x > 0) world->addElement(new Dandelion(world,{position.y,position.x-1}));
                        break;
                    case RIGHT:
                        if(position.x < world->getWidth()-1) world->addElement(new Dandelion(world,{position.y,position.x+1}));
                        break;
                }
        }
    }
    }
}
const char Dandelion::getName() { return DANDELION; }
const void Dandelion::print() { std::cout<<DANDELION; }

Dandelion::~Dandelion() {
    world->fit("* has been eaten");
}
