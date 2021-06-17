#ifndef Guarana_hpp
#define Guarana_hpp

#include <iostream>
#include <string>

#include "Plant.hpp"
#include "Animal.hpp"
#include "World.hpp"
#include "Empty.hpp"
class Guarana : public Plant{
public:
    Guarana();
    Guarana(World *world,CORDS position);
    void action() override;
    void collision(Organism *opponent) override;
    const void print() override;
    const char getName() override;
    ~Guarana();
};
#endif
