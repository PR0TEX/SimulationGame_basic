#ifndef Wolfberries_hpp
#define Wolfberries_hpp

#include <iostream>

#include "Plant.hpp"
#include "Animal.hpp"
#include "World.hpp"
#include "Empty.hpp"

class Wolfberries : public Plant{
public:
    Wolfberries();
    Wolfberries(World *world,CORDS position);
    void action() override;
    void collision(Organism *opponent) override;
    const void print() override;
    const char getName() override;
    ~Wolfberries();
};
#endif
