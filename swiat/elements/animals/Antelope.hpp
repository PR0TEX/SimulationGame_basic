#ifndef Antelope_hpp
#define Antelope_hpp

#include <iostream>
#include "Animal.hpp"
#include "World.hpp"
#include "Empty.hpp"

class Antelope : public Animal {
protected:
    void meet(Organism* opponent) override;
public:
    Antelope();
    Antelope(World *world,const CORDS position);
    void action() override;
    void collision(Organism *opponent) override;
    const void print() override;
    const char getName() override;
    ~Antelope();
};


#endif
