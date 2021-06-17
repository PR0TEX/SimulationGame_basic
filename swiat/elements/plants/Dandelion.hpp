#ifndef Dandelion_hpp
#define Dandelion_hpp

#include <iostream>

#include "Plant.hpp"
#include "World.hpp"
#include "Empty.hpp"

class Dandelion : public Plant{
public:
    Dandelion();
    Dandelion(World *world,CORDS position);
    void action() override;
    const void print() override;
    const char getName() override;
    ~Dandelion();
};
#endif
