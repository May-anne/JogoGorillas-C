#include <curses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

extern char *p1, *p2;

void ranking () {
    char tituloRanking[22] = {"RANKING DOS JOGADORES"};
    int tamanho = strlen(tituloRanking);

    initscr();
    clear();
    noecho();
    curs_set(0);

    WINDOW * janela = newwin(Y,X,0,0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    mvprintw(10, (X-tamanho)/2, "%s", tituloRanking);
    mvprintw(15, (X-tamanho)/2, "Jogador 1: %s", p1);
}