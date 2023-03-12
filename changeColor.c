#include <curses.h>
#include <string.h>
#include "global.h"

int changeColor(char x[3][10], char y[]) //mudar cor ao usar setas down e up
{
    int index = 0;
    int escolha = 0;
    int tamanho = strlen(y);

    WINDOW * janela = newwin(Y, X, 0, 0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    keypad(janela, true);
    mvwprintw(janela, 10, (X - tamanho)/2, "%s", y);

    while(true) {
        for(int i=0; i < 3; i++) {
            if (i == index) {
                wattron(janela, A_REVERSE);
                mvwprintw(janela, i+15, (X-strlen(x[i]))/2, "%s", x[i]);
                wattroff(janela, A_REVERSE);
            } else {
                mvwprintw(janela, i+15, (X-strlen(x[i]))/2, "%s", x[i]);
            }
        }
        escolha = wgetch(janela);

        switch(escolha) {
            case KEY_UP:
                index--;
                if(index == -1)
                    index = 2;
                break;
            case KEY_DOWN:
                index++;
                if(index == 3)
                    index = 0;
                break;
            default:
                break;
        }
        if(escolha == 10){
            break;
        }
    }
   return index;
}