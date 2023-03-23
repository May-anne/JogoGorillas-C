#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"
extern int Hpredios[8];

void buildMap(int nivel) {
    WINDOW * predio;
    predio = newpad(31,155);

    scrollok(predio, true);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    unsigned short h = 0;
    unsigned short c = 0;
    srand(time(NULL));

    for(int i = 0; i < 100; i++){
        for (int j = 0; j < 50; j++) {
            wattron(predio, COLOR_PAIR(1));
            pechochar(predio, '*');
            wattroff(predio, COLOR_PAIR(1));
        }
    }

    for (int i = 0; i < 8; i++) {

    h = 25 - (rand() %nivel);
    prefresh(predio, 0, 0, h, 2+c, 30, 18+c);
    Hpredios [i] = h;

    if(i==0){

        //Macaco 1
        mvprintw(h-3,(c+8)," o");
        mvprintw(h-2,(c+8),"/|\\");
        mvprintw(h-1,(c+8),"/ \\");
        refresh();

    }else if(i==7){

        //Macaco 2
        mvprintw(h-3,(c+8)," o");
        mvprintw(h-2,(c+8),"/|\\");
        mvprintw(h-1,(c+8),"/ \\");
        refresh();
    }

    c = c + 17;
    }

}

