#ifndef Human_hpp
#define Human_hpp

#include "Animal.hpp"
class Human: public Animal{ 
protected:
    int ability=0;
    int prev_power;
    void meet(Organism* opponent) override;
public:
    Human();
    Human(World *world,const CORDS position);

    void action() override;
    void collision(Organism *opponent) override;
    void immortality(Organism *opponent);
    void magicPotion();
    bool abilityLeft();
    void speedLeft();
    bool avaliable(DIRECTION turn,Organism* target);
    const void print() override;
    const char getName() override;
    ~Human();
};

#endif
