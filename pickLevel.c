#include <curses.h>
#include "global.h"

void pickLevel () {

    char dificuldade[3][10] = {"Facil", "Normal", "Dificil"};
    int play(int nivel);
    char titulo[] = {"ESCOLHA UMA DIFICULDADE"};
    int index;
    int ValorLevel = 0;

    WINDOW * janela = newwin(Y, X, 0, 0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    index = changeColor(dificuldade, titulo);

    if (dificuldade[index] == dificuldade[0])
        ValorLevel = 5;
    else if (dificuldade[index] == dificuldade[1])
        ValorLevel = 10;
    else if (dificuldade[index] == dificuldade[2])
        ValorLevel = 15;
    
    play(ValorLevel);
}
