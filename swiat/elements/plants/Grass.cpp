#include "Grass.hpp"

Grass::Grass(){}

Grass::Grass(World *world,CORDS position){
    this->world=world;
    this->position=position;
    this->power=0;
    this->initiative=0;
}

void Grass::action(){
    if(spread()){
        int attemp=0;
        while(attemp < 10 && spread()){
            DIRECTION turn = (DIRECTION) (rand() % 4);
            attemp++;
            if(dynamic_cast<Empty*>(neight(turn, 1))) {
                switch(turn) {
                    case UP:
                        if(position.y > 0) world->addElement(new Grass(world,{position.y-1,position.x}));
                        break;
                    case DOWN:
                        if(position.y < world->getHeight()-1) world->addElement(new Grass(world,{position.y+1,position.x}));
                        break;
                    case LEFT:
                        if(position.x > 0) world->addElement(new Grass(world,{position.y,position.x-1}));
                        break;
                    case RIGHT:
                        if(position.x < world->getWidth()-1) world->addElement(new Grass(world,{position.y,position.x+1}));
                        break;
                }
            }
        }
    }
}
const char Grass::getName(){ return GRASS; }
const void Grass::print() { std::cout<<GRASS; }

Grass::~Grass() {
    world->fit(", has been eaten");
}
