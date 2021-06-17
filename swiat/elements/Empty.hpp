#ifndef Empty_hpp
#define Empty_hpp

#include "Organism.hpp"

class Empty : public Organism{
public:
    Empty();
    Empty(World* world,const CORDS position);
    const void print() override;
    const char getName() override;
    ~Empty();
};
#endif
