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

    //initialize play field, may be able to draw this just once since ncurses refreshes only changes
    int nFieldWidth {12};
    int nFieldHeight {18};
    std::vector<unsigned char> vField(nFieldWidth * nFieldHeight, 0); //swap for wide chars for better characters later, or ints with associations
    for(int iter {}; iter < nFieldWidth * nFieldHeight; iter++){
        if((iter % nFieldWidth == 0) || (iter % nFieldWidth == nFieldWidth - 1) || (iter >= nFieldWidth * nFieldHeight - nFieldWidth)) vField[iter] = 9;
    }

    //Initialize screen
    int rows {};
    int columns {};
    initscr();
    getmaxyx(stdscr, rows, columns);
    noecho();
    raw();

    //initialize variables
    bool bGameOver {false};

    //Game loop
    while(!bGameOver){

        //draw field to stdscr
        for(int x {}; x < nFieldWidth; x++){
            for(int y {}; y < nFieldHeight; y++){
                //replace mvprintw() with printw() and some looping later for efficiency
                mvprintw(y, x, "%c", " ABCDEFG=#"[vField[y * nFieldWidth + x]]);
                

            }
        }


        getch(); //with implied refresh(), actually this will need to be made asynch so blocks can fall without waiting for input? or does Raw do this?
        bGameOver = true; //break loop after once for now
    }

    getch();
    endwin();



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