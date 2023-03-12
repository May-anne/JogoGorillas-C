#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "global.h"

int Hpredios[8];

int main(void){
    char menu[3][10] = {"Playing", "Ranking", "Exit"};
    char titulo[] = {"GORILLAS"};
    int xmax, ymax;
    getmaxyx(stdscr, ymax, xmax);

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
