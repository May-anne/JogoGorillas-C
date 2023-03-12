#include <curses.h>
#include "global.h"

void ranking () {
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    mvwprintw(janela, 10, (xmax/2)-5, "RANKING DOS JOGADORES");
}