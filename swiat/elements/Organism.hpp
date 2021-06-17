#ifndef Organism_hpp
#define Organism_hpp

#include "SHC.h"
#include <stdlib.h>

class World;

class Organism {
    friend World;
protected:
    int power;
    int initiative;
    CORDS position;
    World *world;
    virtual Organism* neight(const DIRECTION turn, const int distance);
public:
    Organism();
    Organism(World *world, const CORDS position);
    
    virtual DIRECTION chooseTurn(CORDS position);
    virtual void action();
    virtual void collision(Organism *opponent);
    virtual const void print()=0;
    virtual const char getName()=0;
    virtual void move(DIRECTION turn);
    
    void kill(Organism* organism);
    void clearPosition(Organism* organism);
    bool allowedField(DIRECTION turn, Organism *target);
    const CORDS getPosition();
    const int getInitiative();
    const int getPower();
    void setPower(int power);
    void setPosition(CORDS position);
    void setInitiative(int initiative);

    virtual ~Organism();
};

#endif
