#ifndef Wolf_hpp
#define Wolf_hpp

#include "Animal.hpp"

class Wolf : public Animal{
protected:
    void meet(Organism *opponent) override;
public:
    Wolf();
    Wolf(World *world,const CORDS position);

    const void print() override;
    const char getName() override;
    ~Wolf();
};
#endif
