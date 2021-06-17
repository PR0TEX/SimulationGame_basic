#include "Guarana.hpp"

Guarana::Guarana() {}

Guarana::Guarana(World *world,CORDS position){
    this->world=world;
    this->position=position;
    this->initiative=0;
    this->power=0;
}
void Guarana::action(){
    if(spread()){
        int attemp=0;
        while(attemp < 10 && spread()){
            DIRECTION turn = (DIRECTION) (rand() % 4);
            attemp++;
            if(dynamic_cast<Empty*>(neight(turn, 1))) {
                switch(turn) {
                    case UP:
                        if(position.y > 0) world->addElement(new Guarana(world,{position.y-1,position.x}));
                        break;
                    case DOWN:
                        if(position.y < world->getHeight()-1) world->addElement(new Guarana(world,{position.y+1,position.x}));
                        break;
                    case LEFT:
                        if(position.x > 0) world->addElement(new Guarana(world,{position.y,position.x-1}));
                        break;
                    case RIGHT:
                        if(position.x < world->getWidth()-1) world->addElement(new Guarana(world,{position.y,position.x+1}));
                        break;
                }
            }
        }
    }
}
void Guarana::collision(Organism *opponent){
    if(dynamic_cast<Animal*>(opponent)) {
        std::string info;
        info+=this->getName();
        info+=" has been eaten by ";
        info+=opponent->getName();
        ((Animal*) opponent)->addPower(3);
        info+=" and its power has increased to ";
        info+=std::to_string(opponent->getPower());
        world->fit(info);
    }
}
const void Guarana::print() { std::cout<<GUARANA; }
const char Guarana::getName() { return GUARANA; }

Guarana::~Guarana() {
    world->fit("^ has been eaten");
}
