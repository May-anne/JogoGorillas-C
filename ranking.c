#include <curses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

extern Play *jogador1, *jogador2;

void ranking () {
    char tituloRanking[22] = {"RANKING DOS JOGADORES"};
    unsigned short tamanho = strlen(tituloRanking);

    initscr();
    clear();
    noecho();
    curs_set(0);

    WINDOW * janela = newwin(Y,X,0,0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    mvprintw(10, (X-tamanho)/2, "%s", tituloRanking);
    mvprintw(15, (X-tamanho)/2 - 10, "Jogador 1: %s", jogador1->nome);
    mvprintw(15, (X-tamanho)/2 + 20, "Placar: %d", jogador1->placar);
    mvprintw(17, (X-tamanho)/2 - 10, "Jogador 2: %s", jogador2->nome);
    mvprintw(17, (X-tamanho)/2 + 20, "Placar: %d", jogador2->placar);

    free(jogador1->nome);
    free(jogador2->nome);
    free(jogador1);
    free(jogador2);
    

    getch(); //Espera resposta para encerrar o programa

    endwin();
    exit(0);
}