#ifndef Plant_hpp
#define Plant_hpp

#include "Organism.hpp"

class Plant : public Organism{
public:
    Plant();
    Plant(World *world,const CORDS position);
    
    const void print() override;
    void action() override;
    void collision(Organism *opponent) override;
    const char getName() override;
    virtual bool spread();
    ~Plant();
};
#endif
