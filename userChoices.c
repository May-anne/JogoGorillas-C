#include <curses.h>
#include "global.h"


void pickLevel () {

    char dificuldade[3][10] = {"Facil", "Normal", "Dificil"};
    char titulo[] = {"ESCOLHA UMA DIFICULDADE"};
    short index;
    unsigned short ValorLevel = 0;

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

void keepPlaying() {
    initscr();
    clear();

    WINDOW * janela = newwin(Y, X, 0, 0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    char options[3][10] = {"Sim", "Nao"};
    char titulo[] = {"Voce deseja continuar jogando?"};
    short index = 0;

    index = changeColor(options, titulo);

    if (options[index] == options[0])
        pickLevel();
    else if(options[index] == options[1])
        ranking();

    getch();
    endwin();

}
