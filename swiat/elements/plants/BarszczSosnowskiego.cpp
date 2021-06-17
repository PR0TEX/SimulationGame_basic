#include "BarszczSosnowskiego.hpp"

BarszczSosnowskiego::BarszczSosnowskiego() {}

BarszczSosnowskiego::BarszczSosnowskiego(World *world, CORDS position){
    this->world=world;
    this->position=position;
    this->power=10;
    this->initiative=0;
}
void BarszczSosnowskiego::action(){
    for(int i=0;i<4;i++){
        if(dynamic_cast<Animal*>(neight((DIRECTION) i, 1))) burn(neight((DIRECTION) i, 1));
    }
    if(spread()){
        int attemp=0;
        while(attemp < 10 && spread()){
            DIRECTION turn = (DIRECTION) (rand() % 4);
            attemp++;
            if(dynamic_cast<Empty*>(neight(turn, 1))) {
                switch(turn) {
                    case UP:
                        if(position.y > 0) world->addElement(new BarszczSosnowskiego(world,{position.y-1,position.x}));
                        break;
                    case DOWN:
                        if(position.y < world->getHeight()-1) world->addElement(new BarszczSosnowskiego(world,{position.y+1,position.x}));
                        break;
                    case LEFT:
                        if(position.x > 0) world->addElement(new BarszczSosnowskiego(world,{position.y,position.x-1}));
                        break;
                    case RIGHT:
                        if(position.x < world->getWidth()-1) world->addElement(new BarszczSosnowskiego(world,{position.y,position.x+1}));
                        break;
                }
        }
        }
    }
}
void BarszczSosnowskiego::burn(Organism *opponent){
    opponent->~Organism();
    kill(opponent);
}
void BarszczSosnowskiego::collision(Organism *opponent){
    std::string info;
    if(dynamic_cast<Animal*>(opponent)){
        info+=opponent->getName();
        info+=" eats ";
        info+=this->getName();
        world->fit(info);
        this->~BarszczSosnowskiego();
        kill(opponent);
        kill(this);
    }
}

const void BarszczSosnowskiego::print() { std::cout<<BS; }
const char BarszczSosnowskiego::getName() { return BS; }

BarszczSosnowskiego::~BarszczSosnowskiego() {
    world->fit("! has been eaten");
}
