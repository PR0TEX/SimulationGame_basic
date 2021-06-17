#include "Organism.hpp"
#include "World.hpp"
#include "Empty.hpp"

Organism::Organism(){};
Organism::Organism(World *world,const CORDS position)
:world(world),position(position){}

void Organism::action(){}
void Organism::collision(Organism *opponent){ }
void const Organism::print(){}

DIRECTION Organism::chooseTurn(CORDS position){
    bool picked=false;
    DIRECTION turn;
    do{
        //srand ( time(NULL) );
        turn = (DIRECTION) (rand()%4);
        if(position.x == 0) {
            if(picked) picked = !picked;
            if(turn != LEFT) picked=true;
            if(position.y != 0) continue;
        }else if(position.y == 0){
            if(picked) picked = !picked;
            if(turn != UP) picked=true;
        }else if(position.x==world->getWidth()){
            if(picked) picked = !picked;
            if(turn != RIGHT) picked=true;
            if(position.y != world->getHeight()) continue;
        }else if(position.y==world->getHeight()){
            if(picked) picked = !picked;
            if(turn != DOWN) picked=true;
        }else picked=true;
    }while(!picked);
    return turn;
}
void Organism::move(DIRECTION turn){
    int tempY=position.y;
    int tempX=position.x;
    do{
        switch(turn) {
            case UP:
                if(position.y > 0){
                position.y--;
                }
                break;
            case DOWN:
                if(position.y < world->getHeight())
                {
                position.y++;

                }
                break;
            case LEFT:
                if(position.x > 0){
                    position.x--;
                }
                break;
            case RIGHT:
                if(position.x < world->getWidth()){
                    position.x++;
                }
                break;
        }
        turn = (DIRECTION) (rand() % 4);
    }while(position.y == tempY && position.x == tempX);
}
Organism* Organism::neight(const DIRECTION turn, const int distance){
    switch(turn) {
        case UP:
            if(position.y > 0) return world->world[position.y-1][position.x];
            break;
        case DOWN:
            if(position.y < world->getHeight() - 1) return world->world[position.y+1][position.x];
            break;
        case LEFT:
            if(position.x > 0) return world->world[position.y][position.x-1];
            break;
        case RIGHT:
            if(position.x < world->getWidth() - 1) return world->world[position.y][position.x+1];
            break;
            
    }
    return 0;
}
void Organism::clearPosition(Organism *organism){
    world->world[organism->getPosition().y][organism->getPosition().x]= new Empty();
}
void Organism::kill(Organism *organism){
    clearPosition(organism);
    world->deleteElement(organism);
    organism->~Organism();
}
bool Organism::allowedField(DIRECTION turn,Organism* target){
    int x=target->getPosition().x;
    int y=target->getPosition().y;
    switch (turn) {
        case UP:
            if(y > 0) return true;
            break;
        case DOWN:
            if(y < world->getHeight()-1) return true;
            break;
        case LEFT:
            if(x > 0) return true;
            break;
        case RIGHT:
            if(x < world->getWidth()-1) return true;
            break;
    }
    return false;
}
const int Organism::getPower() { return power; }
const CORDS Organism::getPosition() { return position; }
const int Organism::getInitiative() { return initiative; }

void Organism::setPower(int power) { this->power=power; }
void Organism::setPosition(CORDS position) { this->position=position; }
void Organism::setInitiative(int initiative) { this->initiative=initiative; }

Organism::~Organism(){}

