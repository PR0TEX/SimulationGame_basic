#ifndef World_hpp
#define World_hpp

#include <string>
#include <vector>
#include <algorithm>
#include "Organism.hpp"

class World{
protected:
    int width;
    int height;
    int round;
    bool play=true;
    std::vector<Organism*> elements;
    std::string terminal;
    void sign();
    const void reTerminal();
public:
    Organism ***world;
    World(const int width,const int height);
    
    const void fit(std::string info);
    const void printWorld();
    void makeRound();
    void game();
    bool emptyField();
    void endGame();
    void addElement(Organism *organism);
    void deleteElement(Organism *organism);
    void prepareElements();
    const int getHeight();
    const int getWidth();
    const int getRound();
    ~World();
};

#endif
