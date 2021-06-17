#include "Plant.hpp"
#include "World.hpp"
#include "Empty.hpp"
#include <iostream>
#include <string>

Plant::Plant(){};
Plant::Plant(World *world,const CORDS position)
{
    this->world=world;
    this->position=position;
}
void const Plant::print(){ std::cout << PLANT; }
const char Plant::getName() { return PLANT; }
void Plant::action(){
    if(spread()){
        int attemp=0;
        while(attemp < 10 && spread()){
            DIRECTION turn = (DIRECTION) (rand() % 4);
            attemp++;
            if(dynamic_cast<Empty*>(neight(turn, 1))){
                move(turn);
            }
        }
    }
}
void Plant::collision(Organism *opponent){
    if(opponent->getPower() > this->getPower()){
        std::string info;
        info+=this->getName();
        info+=" has been eaten by ";
        info+=opponent->getName();
        world->fit(info);
        clearPosition(opponent);
        kill(this);
        opponent->setPosition({this->getPosition().y,this->getPosition().x});
    }
}

bool Plant::spread(){
   // srand(time(NULL));
    int possibility = rand()%100;
    if(possibility > 50) return true;
    return false;
}

Plant::~Plant() {}
