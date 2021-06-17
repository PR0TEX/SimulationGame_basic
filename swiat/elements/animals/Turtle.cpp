#include "Turtle.hpp"


Turtle::Turtle(){}

Turtle::Turtle(World *world,const CORDS position){
    this->world=world;
    this->position=position;
    this->initiative=1;
    this->power=2;
    this->age=0;
}
void Turtle::action(){
    bool WISH=false;
    int possibility=rand()%100;
    if(possibility > 75) WISH=true;
    if(WISH){
        int tempX=getPosition().x;
        int tempY=getPosition().y;
        DIRECTION turn = (DIRECTION) (rand() % 4);
        if(dynamic_cast<Empty*>(neight(turn, 1)) || dynamic_cast<Plant*>(neight(turn, 1))) {
            move(turn);
        }else{
            if(neight(turn, 1)) neight(turn, 1)->collision(this);
            if(dynamic_cast<Empty*>(neight(turn,1))) move(turn);
        }
        if(tempX != getPosition().x || tempY != getPosition().y) {
            std::string info="";
            info+=this->getName();
            info+=POS_CH;
            world->fit(info);
            world->world[tempY][tempX]=new Empty();
        }
        world->world[position.y][position.x]=this;
    }
}
void Turtle::collision(Organism *opponent){
    std::string info;
    if(dynamic_cast<Turtle*>(opponent)) {
        info+=BREED;
        meet(opponent);
    }
    else if(opponent->getPower() >= 5){
        return;
    }else if(this->getPower() > opponent->getPower()){
        clearPosition(this);
        kill(opponent);
        this->setPosition({opponent->getPosition().y,opponent->getPosition().x});
    }else {
        clearPosition(opponent);
        kill(this);
        opponent->setPosition({this->getPosition().y,this->getPosition().x});
    }
}

void Turtle::meet(Organism *opponent){
    DIRECTION turn = chooseTurn(opponent->getPosition());
        switch(turn) {
            case UP:
                if(position.y > 0)
                    if(dynamic_cast<Empty*>(neight(turn, 1))) world->addElement(new Turtle(world,{position.y-1,position.x}));
                break;
            case DOWN:
                if(position.y < world->getHeight()-1) if(dynamic_cast<Empty*>(neight(turn, 1))) world->addElement(new Turtle(world,{position.y+1,position.x}));
                break;
            case LEFT:
                if(position.x > 0) if(dynamic_cast<Empty*>(neight(turn, 1))) world->addElement(new Turtle(world,{position.y,position.x-1}));
                break;
            case RIGHT:
                if(position.x < world->getWidth()-1) if(dynamic_cast<Empty*>(neight(turn, 1))) world->addElement(new Turtle(world,{position.y,position.x+1}));
                break;
        }
    
}

const void Turtle::print() { std::cout<<TURTLE; }
const char Turtle::getName() { return TURTLE; }

Turtle::~Turtle() {
    std::string info;
    info+=this->getName();
    info+=" killed";
    world->fit(info);
}
