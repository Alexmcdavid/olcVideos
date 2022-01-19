#include <ncursesw/ncurses.h>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>

int rotate(int px, int py, int rot);

int main(){
    //Initialize tertrominos
    std::vector<std::string> tetrominos[7];
    std::string i, o, t, j, l, s, z;
    i.append("..X.");
    i.append("..X.");    
    i.append("..X.");    
    i.append("..X.");

    o.append(".XX.");
    o.append(".XX.");
    o.append("....");
    o.append("....");

    t.append("....");
    t.append(".XXX");
    t.append("..X.");
    t.append("....");

    j.append("..X.");
    j.append("..X.");
    j.append("..X.");
    j.append(".XX.");

    l.append(".X..");
    l.append(".X..");
    l.append(".X..");
    l.append(".XX.");

    s.append(".X..");
    s.append(".XX.");
    s.append("..X.");
    s.append("....");

    z.append("..X.");
    z.append(".XX.");
    z.append(".X..");
    z.append("....");




    return 0;
}

//find tetramino block position after rotation
int rotate(int px, int py, int rot){
    switch (rot){
        case 0: return py * 4 + px;
        case 90: return 12 + py - (px * 4);
        case 180: return 15 - (py * 4) - px;
        case 270: return 3 - py + (px*4);
    }    
    return 0;
}