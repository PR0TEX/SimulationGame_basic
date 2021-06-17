#include "World.hpp"
#include <ncurses.h>
#include <curses.h>
#include <iostream>

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    for(int i=0;i<4;i++){
        rand();
    }
    int width,height;
    std::cout << "Enter the height of the board" << std::endl;
    std::cin >> height;
    std::cout << "Enter the width of the board" << std::endl;
    std::cin >> width;
    World* w=new World(width,height);
    w->makeRound();
    w->game();
    return 0;
}
