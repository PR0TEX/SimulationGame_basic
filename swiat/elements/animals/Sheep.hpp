#ifndef Sheep_hpp
#define Sheep_hpp

#include "Animal.hpp"

class Sheep : public Animal {
protected:
    void meet(Organism* opponent) override;
public:
    Sheep();
    Sheep(World *world,const CORDS position);
    const void print() override;
    const char getName() override;
    ~Sheep();
};


#endif
