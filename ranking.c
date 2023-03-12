#include <curses.h>
#include "global.h"

void ranking () {
    int ymax, xmax;
    char tituloRanking[22] = {"RANKING DOS JOGADORES"};

    getmaxyx(stdscr, ymax, xmax);
    initscr();
    noecho();
    curs_set(0);

    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    mvwprintw(janela, 10, (xmax/2)-5, "%s", tituloRanking);
}