#ifndef Grass_hpp
#define Grass_hpp

#include <iostream>

#include "Plant.hpp"
#include "World.hpp"
#include "Empty.hpp"

class Grass : public Plant {
public:
    Grass();
    Grass(World* world,CORDS position);
    void action() override;
    const char getName() override;
    const void print() override;
    ~Grass();
};

#endif
