#ifndef Fox_hpp
#define Fox_hpp

#include <iostream>

#include "Animal.hpp"
#include "World.hpp"
#include "Empty.hpp"
class Fox : public Animal {
protected:
    void meet(Organism* opponent) override;
public:
    Fox();
    Fox(World *world,const CORDS position);
    void action() override;
    const void print() override;
    const char getName() override;
    ~Fox();
};
#endif 
