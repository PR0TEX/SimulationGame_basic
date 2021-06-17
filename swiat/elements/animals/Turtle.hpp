#ifndef Turtle_hpp
#define Turtle_hpp

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "World.hpp"
#include "Empty.hpp"
#include "Plant.hpp"
class Turtle : public Animal {
protected:
    void meet(Organism* opponent) override;
public:
    Turtle();
    Turtle(World *world,const CORDS position);
    void action() override;
    void collision(Organism *opponent) override;
    const void print() override;
    const char getName() override;
    ~Turtle();
};

#endif
