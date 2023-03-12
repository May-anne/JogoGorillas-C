#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"
extern int Hpredios[8];

void buildMapa(int nivel) {
    WINDOW * predio;
    predio = newpad(31,155);

    scrollok(predio, true);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    int h = 0;
    int c = 0;
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

int colisaoPredio (int Hpredios [], int y, int x){ //verificação se bateu no segundo ou nos proxs até o sétimo prédio.
    if ((y>= Hpredios[1] && (x>=20 && x <=36))||(y>= Hpredios[2] && (x>=37 && x <=53))||(y>= Hpredios[3] && (x>=54 && x <=70))||
    (y>= Hpredios[4] && (x>=71 && x <=87))||(y>= Hpredios[5] && (x>=88 && x <=104))|| (y>= Hpredios[5] && (x>=88 && x <=104))||
    (y>= Hpredios[6] && (x>=105 && x <=121)))
    {
        mvprintw(5, 5,"Errou!");
        return 0;
    }

    return 1;
}
