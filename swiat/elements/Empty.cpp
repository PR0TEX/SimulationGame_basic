#include <iostream>
#include "Empty.hpp"

Empty::Empty() {}

Empty::Empty(World *world,const CORDS position)
{
    this->world=world;
    this->position=position;
    this->initiative=0;
}

const char Empty::getName(){ return EMPTY; }
const void Empty::print(){ std::cout<<EMPTY; }

Empty::~Empty() {}
