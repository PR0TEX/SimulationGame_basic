#ifndef Animal_hpp
#define Animal_hpp

#include "Organism.hpp"
#include <stdlib.h>

class Animal : public Organism{
protected:
    int age;
    virtual void meet(Organism* opponent)=0;
public:
    Animal();
    Animal(World *world,const CORDS position);
    virtual void addPower(int add);
    bool attackReturn(Organism* opponent);
    void action() override;
    void collision(Organism *opponent) override;
    void const print() override;
    const char getName() override;
    void setAge(int age);
    const int getAge();
    ~Animal();
};

#endif
