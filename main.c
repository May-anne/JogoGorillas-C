#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "global.h"

int Hpredios[8];
char *p1, *p2;

void pickLevel();
void ranking();

int main(void){
    char menu[3][10] = {"Playing", "Ranking", "Exit"};
    char titulo[] = {"GORILLAS"};
    int index = 0;

    initscr();
    noecho();
    curs_set(0);

    WINDOW * janela = newwin(Y, X, 0, 0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    index = changeColor(menu, titulo);

    if (menu[index] == menu[0])
        pickLevel();
    else if(menu[index] == menu[1])
        ranking();
    else if (menu[index] == menu[2])
        endwin();

    getch();
    endwin();
    return 0;
}
