#include <iostream>
#include <ctime>
#include "Animal.hpp"
#include "World.hpp"
#include "Empty.hpp"
#include "Plant.hpp"
#include "Turtle.hpp"

#define REQ_UP (turn == UP && position.y > 0)
#define REQ_DOWN (turn == DOWN && position.y < world->getHeight() - 1)
#define REQ_LEFT (turn == LEFT && position.x > 0)
#define REQ_RIGHT (turn == RIGHT && position.x < world->getWidth() - 1)

Animal::Animal() {}
Animal::Animal(World *world,const CORDS position)
{
    this->world=world;
    this->position=position;
}

void Animal::action(){
    int tempX=getPosition().x;
    int tempY=getPosition().y;
    DIRECTION turn=UP;
    srand(time(NULL));
    turn=(DIRECTION)(rand()%4);
    if(REQ_UP || REQ_DOWN || REQ_LEFT || REQ_RIGHT)
    {
        if(dynamic_cast<Empty*>(neight(turn, 1))) {
            move(turn);
            world->world[position.y][position.x]=this;
        }
        else neight(turn, 1)->collision(this);
        std::string info="";
        info+=this->getName();
        info+=POS_CH;
        world->fit(info);
        world->world[tempY][tempX]=new Empty();
    }
}   
void Animal::collision(Organism *opponent){
    if(attackReturn(opponent)) return;
    std::string info="";
    info+=this->getName();
    if(this->getName()==opponent->getName()) {
        info+=BREED;
        meet(opponent);
            
    }else if(dynamic_cast<Plant*>(opponent))
    {
        opponent->collision(this);
    }else if(this->getPower() > opponent->getPower()){
        info+=" defeated ";
        info+=opponent->getName();
        clearPosition(this);
        kill(opponent);
        this->setPosition({opponent->getPosition().y,opponent->getPosition().x});
    }else {
        info+=" has been defeated by ";
        info+=opponent->getName();
        clearPosition(opponent);
        kill(this);
        opponent->setPosition({this->getPosition().y,this->getPosition().x});
    }
    world->fit(info);
}

void Animal::addPower(int add){
    this->power=this->power + add;
}
bool Animal::attackReturn(Organism *opponent)
{
    if(dynamic_cast<Turtle*>(opponent) && this->getPower() >= 5) return true;
    return false;
}
void Animal::setAge(int age){
    this->age=age;
}
const int Animal::getAge(){
    return this->age;
}
const void Animal::print(){ std::cout << ANIMAL; }
const char Animal::getName() { return ANIMAL; }
Animal::~Animal() {}
