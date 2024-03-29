#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "global.h"

extern int Hpredios[8];
extern Play *jogador1, *jogador2;

int play(int nivel) {
    initscr();
    clear();
    refresh();

    unsigned short vez = 0;
    int controle;

    WINDOW * janela = newwin(Y, X, 0, 0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    curs_set(1);
    echo();

    buildMap(nivel); //Chamada de função para construir mapa

    if(jogador1->nome == NULL){
        jogador1->nome = malloc(20 *sizeof(char));
        mvprintw(1, 1,"Nome Jogador 1: ");
        getstr(jogador1->nome);

    } else {
        mvprintw(1,1,"Nome Jogador 1: %s", jogador1->nome);
    }

    if(jogador2->nome == NULL){
        jogador2->nome  = malloc(20 * sizeof(char));
        mvprintw(1,110,"Nome Jogador 2: ");
        getstr(jogador2->nome);

    } else {
        mvprintw(1,110,"Nome Jogador 2: %s", jogador2->nome);
    }
                
    mvprintw(2,1, "Placar: %d", jogador1->placar);
    refresh();
    
    mvprintw(2, 110, "Placar: %d", jogador2->placar);
    refresh();

    while (true)
    {
        refresh();
        echo();

        if(vez%2==0) { //Vez jogador 1
            refresh();
            curs_set(1);

            //Imprime mensagem de angulo e velocidade na tela e coleta string escrita e imprime na tela
            escolha_1:
                mvprintw(3,1,"Angulo:");
                refresh();
                getstr(jogador1->angulo);
                mvprintw(3,8,"%s", jogador1->angulo);
                refresh();

                mvprintw(4,1,"Velocidade:");
                refresh();
                getstr(jogador1->velocidade);
                mvprintw(4,12,"%s",jogador2->velocidade);
                refresh();

                mvprintw(3,1,"                               ");
                mvprintw(4,1,"                               ");
                mvprintw(Y/2-15, X/2-2, "                         ");
                curs_set(0);
                refresh();

            if((strlen(jogador1->velocidade)==0)||(strlen(jogador1->angulo)==0))
            goto escolha_1; //filtro de escolha do joagador

            //Conversão char -> int
            jogador1->angtoInt = atoi(jogador1->angulo);
            jogador1->veltoInt = atoi(jogador1->velocidade);
            throwBanana(jogador1->angtoInt, jogador1->veltoInt, 1); //Lançamento da Banana
            vez++;
            
            controle = getch();
            noecho();
            if(controle=='q'){ //Para sair do jogo a qualquer momento (em que não esteja sendo pedido algum dado)
                break;
            }
            refresh();

        } else { //Vez jogador 2
            curs_set(1);
            refresh();

            escolha_2:
                mvprintw(3,110,"Angulo:");
                refresh();
                getstr(jogador2->angulo);
                mvprintw(3,117,"%s", jogador2->angulo);
                refresh();

                mvprintw(4,110,"Velocidade:");
                refresh();
                getstr(jogador2->velocidade);
                mvprintw(4,121,"%s", jogador2->velocidade);
                refresh();

                mvprintw(3,110,"                         ");
                mvprintw(4,110,"                         ");
                mvprintw(Y/2-15, X/2-2,"                         ");

                curs_set(0);
                refresh();
                
            if((strlen(jogador2->velocidade)==0)||(strlen(jogador2->angulo)==0))
                goto escolha_2;

            //Conversão char -> int
            jogador2->angtoInt = atoi(jogador2->angulo);
            jogador2->veltoInt = atoi(jogador2->velocidade);
            throwBanana(jogador2->angtoInt, jogador2->veltoInt, 2);
            vez++;

            refresh();

            controle = getch();
            noecho();
            if(controle=='q'){ //Para sair do jogo a qualquer momento (em que não esteja sendo pedido algum dado)
                break;
            }

        }
    }
    return 0;
}
