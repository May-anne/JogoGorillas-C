#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "global.h"

extern int Hpredios[8];
extern char info[10][20];

int play(int nivel) {
    initscr();
    clear();
    refresh();

    void buildMap(int nivel);

    int ver;

    WINDOW * janela = newwin(Y, X, 0, 0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    buildMap(nivel); //Chamada de função para construir mapa

    char jogador1[] = {"Mayanne"};
    char jogador2[] = {};
    char ang1[5], ang2[5], vel1[5], vel2[5];
    int ang1toInt, ang2toInt,vel1toInt,vel2toInt;
    int vez = 0;
    int controle;

    while (true)
    {
        refresh();
        echo();

        if(vez%2==0) { //Vez jogador 1

                if(sizeof(jogador1) == 0){ //Informações dos jogadores (nome)
                    curs_set(1);
                    mvprintw(1, 1,"Nome Jogador 1: ");
                    getstr(jogador1);
                    strcpy(info[0], jogador1);

                } else {
                    strcpy(info[0], jogador1);
                    mvprintw(1,1,"Nome Jogador 1: %s",jogador1);
                }

                refresh();

            curs_set(1);
            //Imprime mensagem de angulo e velocidade na tela e coleta string escrita e imprime na tela
            mvprintw(2,1,"Angulo:");
            refresh();
            getstr(ang1);
            mvprintw(2,8,"%s",ang1);
            refresh();

            mvprintw(3,1,"Velocidade:");
            refresh();
            getstr(vel1);
            mvprintw(3,12,"%s",vel1);
            refresh();

            mvprintw(2,1,"                                                                    ");
            mvprintw(3,1,"                                                                    ");
            curs_set(0);
            refresh();

            //Conversão char -> int
            ang1toInt = atoi(ang1);
            vel1toInt = atoi(vel1);
            throwBanana(ang1toInt, vel1toInt, 1); //Lançamento da Banana
            vez++;

            refresh();

        } else { //Vez jogador 2
            if(sizeof(jogador2) == 0){
                curs_set(1);
                mvprintw(1,110,"Nome Jogador 2: ");
                getstr(jogador2);

                strcpy(info[1], jogador2);

            } else {
                strcpy(info[1], jogador2);
                mvprintw(1,110,"Nome Jogador 2: %s",jogador2);
            }

            curs_set(1);
            mvprintw(2,110,"Angulo:");
            refresh();
            getstr(ang2);
            mvprintw(2,117,"%s",ang2);
            refresh();
            ang2toInt = atoi(ang2);

            mvprintw(3,110,"Velocidade:");
            refresh();
            getstr(vel2);
            mvprintw(3,121,"%s",vel2);
            refresh();
            vel2toInt = atoi(vel2);

            mvprintw(2,110,"                         ");
            mvprintw(3,110,"                         ");

            curs_set(0);
            refresh();

            throwBanana(ang2toInt, vel2toInt, 2);
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
