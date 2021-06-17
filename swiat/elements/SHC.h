#ifndef SHC_h
#define SHC_h
#include "Organism.hpp"
//general
#define ANIMAL 'a'
#define EMPTY '.'
#define PLANT 'p'
//animals
#define WOLF 'W'
#define SHEEP 'S'
#define FOX 'F'
#define TURTLE 'T'
#define ANTELOPE 'A'
#define HUMAN 'H'
//plants on board
#define GRASS ','
#define DANDELION '*'
#define GUARANA '^'
#define WOLFBERRIES '@'
#define BS '!' // barszcz Sosnowskiego
//formula constants
#define POS_CH " moves, from (" + std::to_string(tempY)+","+std::to_string(tempX)+") to ("+std::to_string(getPosition().y)+","+std::to_string(getPosition().x)+")";
#define BREED "s breed at (" +std::to_string(getPosition().y)+","+std::to_string(getPosition().x)+")";
#define POSIT "("+std::to_string(getPosition().y)+","+std::to_string(getPosition().x)+")";
#define HUM_CH "Human moves to ("+std::to_string(getPosition().x)+","+std::to_string(getPosition().y)+")";

struct CORDS{
    int y;
    int x;
};

enum DIRECTION{
  UP,
  DOWN,
  RIGHT,
  LEFT
};
enum ABILITY{
    IMMORTALITY,
    MAGIC_POTION,
    ANTELOPE_SPEED,
    ALZUR_SHIELD,
    HOLOCAUST,
    NORMAL
};
#endif
