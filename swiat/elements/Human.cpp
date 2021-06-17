#include <ncurses.h>
#include <curses.h>
#include <iostream>
#include "Human.hpp"
#include "World.hpp"
#include "Empty.hpp"
#include "Plant.hpp"

Human::Human(){}
Human::Human(World *world,const CORDS position){
    this->world=world;
    this->position=position;
    initiative=4;
    power=5;
}
void Human::action(){
    int tempY = position.y;
    int tempX = position.x;
    abilityLeft();
    DIRECTION turn=(DIRECTION) 0;
    char key;
    std::string info="";
    std::cout << "Press to move: |w-UP|s-DOWN|d-RIGHT|a-LEFT|" <<std::endl;
    std::cout << "Press q to quit"<<std::endl;
    std::cout << "H move:";
    do{
        std::cin >> key;
        switch(key) {
            case 'w':
                turn = UP;
                break;
            case 's':
                turn = DOWN;
                break;
            case 'a':
                turn = LEFT;
                break;
            case 'd':
                turn = RIGHT;
                break;
            case 'q':
                kill(this);
                return;
        }
    }while(!allowedField(turn, this));
    
    if(dynamic_cast<Empty*>(neight(turn, 1))) {
        move(turn);
        world->world[tempY][tempX]= new Empty();
        world->world[position.y][position.x]=this;
    }
    else this->collision(neight(turn, 1));
    info=HUM_CH;
    world->fit(info);
}
void Human::collision(Organism *opponent){
    if(attackReturn(opponent)) return;
    if(opponent->getName() == EMPTY) {
        action();
        return;
    }
    char key;
    if(abilityLeft()){
        std::cout<<"Magic potion is avaliable, if you wonna use press p, else press n"<<std::endl;
        std::cin >> key;
        if(key == 'p') magicPotion();
    }
    if(opponent->getPower() > this->getPower()){
        clearPosition(opponent);
        kill(this);
        opponent->setPosition({this->getPosition().y,this->getPosition().x});
        
    }else {
        clearPosition(this);
        kill(opponent);
        this->setPosition({opponent->getPosition().y,opponent->getPosition().x});
        
    }
    world->world[this->getPosition().y][this->getPosition().x]=this;
}
const void Human::print(){ std::cout<<HUMAN; }
const char Human::getName() { return HUMAN; }

void Human::meet(Organism *opponent) {}

bool Human::avaliable(DIRECTION turn,Organism* target){
    int x=target->getPosition().x;
    int y=target->getPosition().y;
    switch (turn) {
        case UP:
            if(y > 0){
                if(dynamic_cast<Empty*>(world->world[y-1][x]) || dynamic_cast<Plant*>(world->world[y-1][x])) return true;
            }
            break;
        case DOWN:
            if(y < world->getHeight()-1){
                if(dynamic_cast<Empty*>(world->world[y+1][x]) || dynamic_cast<Plant*>(world->world[y+1][x])) return true;
            }
            break;
        case LEFT:
            if(x > 0){
                if(dynamic_cast<Empty*>(world->world[y][x-1]) || dynamic_cast<Plant*>(world->world[y][x-1])) return true;
            }
            break;
        case RIGHT:
            if(x < world->getWidth()-1){
                if(dynamic_cast<Empty*>(world->world[y][x+1]) || dynamic_cast<Plant*>(world->world[y][x+1])) return true;
            }
            break;
    }
    return false;
}
bool Human::abilityLeft(){
    if(ability == 0) return true;
    else if(ability > 0) {
        ability--;
        if(this->power > this->prev_power){
            this->power--;
            std::cout<<"The potion weakens, power="<<this->getPower()<<std::endl;
        }
    }
    return false;
}

void Human::magicPotion(){
    world->fit("Potion...");
    this->prev_power=this->power;
    this->setPower(10);
    this->ability=10;
}

Human::~Human(){
    std::string info;
    info+=this->getName();
    info+=" killed ";
    world->fit(info);
    world->endGame();
}

