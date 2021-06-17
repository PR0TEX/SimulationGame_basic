#ifndef BarszczSosnowskiego_hpp
#define BarszczSosnowskiego_hpp

#include <iostream>

#include "Plant.hpp"
#include "Animal.hpp"
#include "World.hpp"
#include "Empty.hpp"

class BarszczSosnowskiego : public Plant{
public:
    BarszczSosnowskiego();
    BarszczSosnowskiego(World *world,CORDS position);
    void action() override;
    void burn(Organism *opponent);
    void collision(Organism *opponent) override;
    const void print() override;
    const char getName() override;
    ~BarszczSosnowskiego();
};

#endif
