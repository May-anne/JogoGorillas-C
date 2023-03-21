#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "global.h"

extern int Hpredios[8];

typedef struct{
    char* nome;
    char angulo[5], velocidade[5];
    int angtoInt, veltoInt;
    } Play;
Play* jogador1, jogador2;

int play(int nivel) {
    initscr();
    clear();
    refresh();
    free(jogador1);

    int ver;
    int vez = 0;
    int controle;

    WINDOW * janela = newwin(Y, X, 0, 0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    buildMap(nivel); //Chamada de função para construir mapa

    jogador1 = malloc(10*sizeof(Play));

    if(jogador1->nome == NULL){
        jogador1->nome = (char *) malloc(sizeof(char*));
        mvprintw(1, 1,"Nome Jogador 1: ");
        getstr(jogador1[0].nome);
    }else {
        mvprintw(1,1,"Nome Jogador 1: %s",jogador1[0].nome);
    }

    while (true)
    {
        refresh();
        echo();

        if(vez%2==0) { //Vez jogador 1

                /*if(jogador1.nome == NULL){ //Informações dos jogadores (nome)
                    curs_set(1);
                    mvprintw(1, 1,"Nome Jogador 1: ");
                    getstr(jogador1.nome);

                } else {
                    mvprintw(1,1,"Nome Jogador 1: %s",jogador1.nome);
                }*/

                refresh();

            curs_set(1);
            //Imprime mensagem de angulo e velocidade na tela e coleta string escrita e imprime na tela
            mvprintw(2,1,"Angulo:");
            refresh();
            getstr(jogador1[1].angulo);
            mvprintw(2,8,"%s", jogador1[1].angulo);
            refresh();

            mvprintw(3,1,"Velocidade:");
            refresh();
            getstr(jogador1[2].velocidade);
            mvprintw(3,12,"%s",jogador1[2].velocidade);
            refresh();

            mvprintw(2,1,"                                                                    ");
            mvprintw(3,1,"                                                                    ");
            curs_set(0);
            refresh();

            //Conversão char -> int
            jogador1[3].angtoInt = atoi(jogador1[1].angulo);
            jogador1[3].veltoInt = atoi(jogador1[2].velocidade);
            throwBanana(jogador1[3].angtoInt, jogador1[3].veltoInt, 1); //Lançamento da Banana
            vez++;

            refresh();

        } else { //Vez jogador 2
            if(strlen(jogador2.nome) == 0){
                curs_set(1);
                mvprintw(1,110,"Nome Jogador 2: ");
                getstr(jogador2.nome);

            } else {
                mvprintw(1,110,"Nome Jogador 2: %s",jogador2.nome);
            }

            curs_set(1);
            mvprintw(2,110,"Angulo:");
            refresh();
            getstr(jogador2.angulo);
            mvprintw(2,117,"%s",jogador2.angulo);
            refresh();

            mvprintw(3,110,"Velocidade:");
            refresh();
            getstr(jogador2.velocidade);
            mvprintw(3,121,"%s",jogador2.velocidade);
            refresh();

            mvprintw(2,110,"                         ");
            mvprintw(3,110,"                         ");

            curs_set(0);
            refresh();

            jogador2.angtoInt = atoi(jogador2.angulo); //Conversão char -> int
            jogador2.veltoInt = atoi(jogador2.velocidade);
            throwBanana(jogador2.angtoInt, jogador2.veltoInt, 2);
            vez++;

            refresh();

            controle = getch();
            noecho();
            if(controle=='q'){
                break;
            }

    }
    //delwin(predio);
    }
    return 0;
}
