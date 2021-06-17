#include "Wolfberries.hpp"

Wolfberries::Wolfberries() {}

Wolfberries::Wolfberries(World *world, CORDS position){
    this->world=world;
    this->position=position;
    this->power=99;
    this->initiative=0;
}
void Wolfberries::action(){
    if(spread()){
        int attemp=0;
        while(attemp < 10 && spread()){
            DIRECTION turn = (DIRECTION) (rand() % 4);
            attemp++;
            if(dynamic_cast<Empty*>(neight(turn, 1))) {
                switch(turn) {
                    case UP:
                        if(position.y > 0) world->addElement(new Wolfberries(world,{position.y-1,position.x}));
                        break;
                    case DOWN:
                        if(position.y < world->getHeight()-1) world->addElement(new Wolfberries(world,{position.y+1,position.x}));
                        break;
                    case LEFT:
                        if(position.x > 0) world->addElement(new Wolfberries(world,{position.y,position.x-1}));
                        break;
                    case RIGHT:
                        if(position.x < world->getWidth()-1) world->addElement(new Wolfberries(world,{position.y,position.x+1}));
                        break;
                }
            }
        
        }
    }
}
void Wolfberries::collision(Organism *opponent){
    std::string info;
    if(dynamic_cast<Animal*>(opponent)) {
        info+=this->getName();
        info+=" has been eaten by ";
        info+=opponent->getName();
        kill(opponent);
        kill(this);
    }

}
const void Wolfberries::print() { std::cout << WOLFBERRIES; }
const char Wolfberries::getName() { return WOLFBERRIES; }

Wolfberries::~Wolfberries() {
    world->fit("@ has been eaten");
}
