#include <curses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

extern Play *jogador1, *jogador2;

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
    mvprintw(15, (X-tamanho)/2 - 3, "Jogador 1: %s\tPlacar: %d", jogador1->nome, jogador1->placar);
    mvprintw(17, (X-tamanho)/2  - 3, "Jogador 1: %s\tPlacar: %d", jogador2->nome, jogador2->placar);

    getch();
    endwin();
    exit(0);
}