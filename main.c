#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "global.h"

int xmax, ymax;

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

int main(void){
    char menu[3][10] = {"Playing", "Ranking", "Exit"};
    char titulo[] = {"GORILLAS"};

    initscr();
    noecho();
    curs_set(0);

    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    int index = mudarCor(menu, titulo);

    if (menu[index] == menu[0])
        picklevel();
    else if(menu[index] == menu[1])
        ranking();
    else if (menu[index] == menu[2])
        endwin();

    getch();
    endwin();
    return 0;
}
