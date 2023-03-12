#include <curses.h>
#include "global.h"

void picklevel () {
    int play(int nivel);

    char dificuldade[3][10] = {"Facil", "Normal", "Dificil"};
    char titulo[] = {"ESCOLHA UMA DIFICULDADE"};
    int xmax, ymax, index;
    int ValorLevel = 0;
    
    getmaxyx(stdscr, ymax, xmax);

    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    index = mudarCor(dificuldade, titulo);

    if (dificuldade[index] == dificuldade[0])
        ValorLevel = 5;
    else if (dificuldade[index] == dificuldade[1])
        ValorLevel = 10;
    else if (dificuldade[index] == dificuldade[2])
        ValorLevel = 15;
    play(ValorLevel);
}
