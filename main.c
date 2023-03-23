#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "global.h"

int Hpredios[8];
Play *jogador1, *jogador2;

int main(void){
    char menu[3][10] = {"Jogar", "Ranking", "Sair"};
    char titulo[] = {"GORILLAS"};
    unsigned short index = 0;

    jogador1 = calloc(1, sizeof(Play));
    jogador2 = calloc(1, sizeof(Play));

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
    else if (menu[index] == menu[2]){
        free(jogador1);
        free(jogador2);
        endwin();
    }

    getch();
    endwin();
    return 0;
}
