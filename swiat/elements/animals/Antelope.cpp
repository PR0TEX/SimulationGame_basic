#include "Antelope.hpp"


Antelope::Antelope(){}

Antelope::Antelope(World *world,const CORDS position){
    this->world=world;
    this->position=position;
    this->initiative=4;
    this->power=4;
    this->age=0;
}
void Antelope::action(){
    for(int i=0;i<4;i++){
        rand();
    }
    int tempX=getPosition().x;
    int tempY=getPosition().y;
    DIRECTION turn = (DIRECTION) (rand()%4);
    if(dynamic_cast<Empty*>(neight(turn, 1))){
        if((turn == UP && position.y < world->getHeight()-2) || (turn==DOWN && position.y > 1) || (turn==LEFT && position.x>1) || (turn==RIGHT && position.x < world->getWidth()-2))
        {
                if(position.y < world->getHeight()-2) {
                    clearPosition(this);
                    if(neight(turn, 1)->getName() == EMPTY){
                        if(neight(turn, 2)->getName() == EMPTY){
                            this->setPosition({getPosition().y+2,getPosition().x});
                        }
                        else {
                            this->setPosition({getPosition().y+1,getPosition().x});
                            neight(turn, 1)->collision(this);
                            if(neight(turn, 1)->getName() == EMPTY)
                                this->setPosition({getPosition().y+1,getPosition().x});
                        }
                    } else{
                        neight(turn, 1)->collision(this);
                        if(neight(turn, 1)->getName() == EMPTY)
                            this->setPosition({getPosition().y+1,getPosition().x});
                    }
                }
            
            world->world[this->getPosition().y][this->getPosition().x]=this;
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
void Antelope::collision(Organism *opponent){
    srand ( time(NULL) );
    if(attackReturn(opponent)) return;
    std::string info;
    info+=getName();
    int possibility=rand()%100;
    bool WISH=true;
    if(possibility < 50) WISH=false;
    if(dynamic_cast<Antelope*>(opponent)){
        info+=BREED;
        meet(opponent);
    }
    else if(WISH){
        info+=" decides to run away";
        bool free=false;
        char part;
        int div=4;
        do{
            srand ( time(NULL) );
            int temp=rand() % div;
            if(temp==UP || temp==DOWN) part='y';
            else part='x';
            if(part=='y'){
                if(temp==UP && position.y > 0 && world->world[position.y - 1][position.x]->getName() == EMPTY) {
                    free=true;
                    move(UP);
                }
                else if(position.y<world->getHeight()-1 && world->world[position.y + 1][position.x]->getName() == EMPTY) {
                    free=true;
                    move(DOWN);
                }
            }else{
                if(temp==LEFT && position.x>0 && world->world[position.y][position.x-1]->getName() == EMPTY) {
                    free=true;
                    move(LEFT);
                }
                else if(position.x<world->getWidth()-1 && world->world[position.y][position.x+1]->getName() == EMPTY) {
                    free=true;
                    move(RIGHT);
                }
                
            }
            world->world[position.y][position.x]=this;
            div--;
        }while(!free && div > 1);
    }else if(this->getPower() > opponent->getPower()){
        info+=" defeated ";
        info+=opponent->getName();
        clearPosition(this);
        kill(opponent);
        this->setPosition({opponent->getPosition().y,opponent->getPosition().x});
    }else{
        info+=" was defeated by ";
        info+=opponent->getName();
        clearPosition(opponent);
        kill(this);
        opponent->setPosition({this->getPosition().y,this->getPosition().x});
    }
    world->fit(info);
}
void Antelope::meet(Organism *opponent){
    DIRECTION turn = chooseTurn(opponent->getPosition());
    if(dynamic_cast<Empty*>(neight(turn, 1))){
        switch(turn) {
            case UP:
                if(position.y > 0) world->addElement(new Antelope(world,{position.y-1,position.x}));
                break;
            case DOWN:
                if(position.y < world->getHeight()-1) world->addElement(new Antelope(world,{position.y+1,position.x}));
                break;
            case LEFT:
                if(position.x > 0) world->addElement(new Antelope(world,{position.y,position.x-1}));
                break;
            case RIGHT:
                if(position.x < world->getWidth()-1) world->addElement(new Antelope(world,{position.y,position.x+1}));
                break;
        }
    }
}
const void Antelope::print() { std::cout<<ANTELOPE; }
const char Antelope::getName() { return ANTELOPE; }

Antelope::~Antelope() {
    std::string info;
    info+=this->getName();
    info+=" killed";
    world->fit(info);
}
