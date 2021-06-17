#include "World.hpp"
#include "Empty.hpp"
#include "Wolf.hpp"
#include "Sheep.hpp"
#include "Fox.hpp"
#include "Turtle.hpp"
#include "Antelope.hpp"
#include "Grass.hpp"
#include "Dandelion.hpp"
#include "Guarana.hpp"
#include "Wolfberries.hpp"
#include "BarszczSosnowskiego.hpp"
#include "Human.hpp"
#include <algorithm>
#include <iostream>

#define SIGNS "|H-Human|W-Wolf|S-Sheep|F-Fox|T-Turtle|A-Antelope|(,)-grass|(*)-dandelion|(^)-guarana|(@)-wolfberry|(!)-barszcz sosnowskiego|"<< std::endl;
struct order{
    bool operator() (Organism* a,Organism* b){
        if(a == NULL || b==NULL) return false;
        if(a->getInitiative() > b->getInitiative()) return true;
        else if(b->getInitiative() > a->getInitiative()) return false;
        else if(dynamic_cast<Animal*>(a) && dynamic_cast<Animal*>(b)){
            if(((Animal*) a)->getAge() > ((Animal*) b)->getAge()) return true;
            
        }
        return false;
    }
};
World::World(const int width,const int height):height(height),width(width){
    world=new Organism**[height];
    for(int i=0;i<height;i++) world[i] = new Organism*[width];
    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) world[i][j] = new Empty();
    }
}
void World::addElement(Organism *organism){
    elements.push_back(organism);
    if(dynamic_cast<Empty*>(world[organism->getPosition().y][organism->getPosition().x])) world[organism->getPosition().y][organism->getPosition().x]=organism;
}
void World::deleteElement(Organism *organism){
    int i=0;
    while(elements[i] != organism && i < elements.size()){
        i++;
    }
    elements[i] = new Empty();
}
void World::prepareElements(){
    for(int i=0;i<elements.size();i++){
        if(elements[i] == NULL) {
            elements.erase(elements.begin()+i);
        }
    }
    sort(elements.begin(),elements.end(),order());
}
void World::makeRound(){
    Wolf* w1 = new Wolf(this,{2,6});
    Wolf* w2 = new Wolf(this,{4,5});
    Fox* f1=new Fox(this,{4,6});
    Fox* f2=new Fox(this,{8,5});
    Sheep* s1=new Sheep(this,{8,5});
    Sheep* s2=new Sheep(this,{4,3});
    Turtle* t1=new Turtle(this,{1,0});
    Turtle* t2=new Turtle(this,{4,0});
    Antelope* a1=new Antelope(this,{8,2});
    Antelope* a2=new Antelope(this,{4,7});
    Dandelion* d1=new Dandelion(this,{8,10});
    Grass* g1=new Grass(this,{5,9});
    Guarana* gu1=new Guarana(this, {6,0});
    Fox* f3=new Fox(this,{6,0});
    Wolfberries* wb1=new Wolfberries(this,{4,4});
    BarszczSosnowskiego* bs1=new BarszczSosnowskiego(this,{3,4});
    BarszczSosnowskiego* bs2=new BarszczSosnowskiego(this,{8,1});
    BarszczSosnowskiego* bs3=new BarszczSosnowskiego(this,{5,3});
    Human* p1=new Human(this,{0,0});
    
    addElement(p1);
    addElement(bs1);
    addElement(bs2);
    addElement(bs3);
    addElement(wb1);
    addElement(gu1);
    addElement(f3);
    addElement(d1);
    addElement(g1);
    addElement(w1);
    addElement(w2);
    addElement(f1);
    addElement(f2);
    addElement(s1);
    addElement(s2);
    addElement(t1);
    addElement(t2);
    addElement(a1);
    addElement(a2);
}
void World::game(){
    prepareElements();
    sign();
    std::cout << "START" <<std::endl;
    while(true){
            if(play)
            {
            printWorld();
            for(int i=0;i<elements.size();i++){
                if(dynamic_cast<Animal*>(elements[i])){
                    int age=((Animal*) elements[i])->getAge();
                    age++;
                    ((Animal*) elements[i])->setAge(age);
                }
                elements[i]->action();
            }
            prepareElements();
            std::cout << std::endl;
            }else {
                printWorld();
                std::cout << "END" <<std::endl;
                std::cout<<"ROUND NUMBER "<<this->round <<std::endl<< "HUMAN DIED - GAME OVER";
                return;
            }
        this->round++;
        }
    
}
void World::endGame(){
    this->play=false;
}
const void World::printWorld() {
    for(int i=0;i<=height;i++){
        if(i==0) std::cout<<"-";
        if(i > 0) std::cout<<"|";
        for(int j=0;j<width;j++){
            if(i==0) std::cout<<"-";
            else world[i-1][j]->print();
            if(i > 0 && j==width-1) std::cout<<"|";
        }
        if(i==0) std::cout<<"-";
        std::cout<<std::endl;
    }
    for(int i=0;i<=width+1;i++) std::cout<<"-";
    std::cout<<std::endl;
    reTerminal();
}
const int World::getHeight() { return height; }
const int World::getWidth() { return width; }
const int World::getRound() { return round; }

void World::sign(){
    std::cout << "Autor: Paweł Domaradzki" << std::endl;
    std::cout << "Indeks: 187586" <<std::endl;
    std::cout << SIGNS ;
}
const void World::fit(std::string info){
    this->terminal+=info;
    this->terminal+='\n';
}
const void World::reTerminal(){
    std::cout<< this->terminal<<std::endl;
    terminal="";
}

