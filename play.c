#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "global.h"

extern int Hpredios[8];

int play(int nivel) {
    initscr();
    clear();
    refresh();

    int colisaoPredio(int Hpredios [], int y, int x);
    void buildMapa(int nivel);

    int ver;

    WINDOW * janela = newwin(32, 140, 0, 0);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    buildMapa(nivel);

    char jogador1[10];
    char jogador2 [10];
    int ang1n,ang2n,vel1n,vel2n;
    char ang1[5],ang2[5],vel1[5],vel2[5];
    int vez = 0;
    int controle;
    int g = 10;


    while (true)
    {
        refresh();
        echo();
        if(vez%2==0){ //Vez jogador 1
            if(vez==0){

                //Coleta nomes dos jogadores e armazena nos arrays
                curs_set(1);//cursor visivel

                //Imprime nomes na tela
                if(jogador1[0] == '\0'){
                    mvprintw(1,1,"Nome Jogador 1: ");
                    getstr(jogador1);
                } else {
                    mvprintw(1,17,"%s",jogador1);
                }

                if(jogador2[0] == '\0'){
                    mvprintw(1,110,"Nome Jogador 2: ");
                    getstr(jogador2);
                } else {
                    mvprintw(1,126,"%s",jogador2);
                }
                refresh();

            }

            //Imprime mensagem de angulo e velocidade na tela e coleta string escrita e imprime na tela
            mvprintw(2,1,"Angulo:");
            refresh();
            getstr(ang1);
            mvprintw(2,8,"%s",ang1);
            refresh();
            ang1n=atoi(ang1);//converte array de char para int

            mvprintw(3,1,"Velocidade:");
            refresh();
            getstr(vel1);
            mvprintw(3,12,"%s",vel1);
            refresh();
            vel1n=atoi(vel1);

            mvprintw(2,1,"                                                                    ");
            mvprintw(3,1,"                                                                    ");

            curs_set(0);
            refresh();

            //Lançamentp
            float angRad = (ang1n*3.14)/180;
            double seno = sin(angRad); //calcular o sen com a função sin()
            double cose = cos(angRad);
            float tempo = fabs(((2*vel1n)*(cose))/g);
            

            for (float t=0; t < tempo+10; t += 0.1) {
                int x = 11 + abs(vel1n) * (cose) * t; // x = abs(11 + vel1n * cose * t)
                int y = (Hpredios[0]-2) - (abs(vel1n) * (seno) * t) + ((g*(t*t))/2); // y = (hmacaco1-1) - abs((vel1n * seno * t) + (g*(t*t))/2)

                wattron(janela,COLOR_PAIR(2));                    
                mvprintw(y,x, "Z");
                wattroff(janela,COLOR_PAIR(2));
                usleep(100000);
                refresh();
                
                mvprintw(y,x, " ");
                

            //macaco 1 -> macaco 2
                if ((y <= Hpredios[7]-1 && y >= Hpredios[7]-3) && (x >= 128 && x <= 130 )){
                    mvprintw(5, 5,"Voce acertou!");
                    break;
                } else if (y >= Hpredios[0] && (x >= 12 && x <= 19 )){ // o próprio predio do macaco 1
                    mvprintw(5, 5,"Errou!");
                    break;
                } else if (y>= Hpredios[7] && (x>=122 && x <=138)){ //inicio do oitavo predio
                    mvprintw(5, 5,"Errou!");
                    break; }
                else if(y == Hpredios[0] && x == 12){
                    mvprintw(5, 5,"Errou!");
                    break;
                }
                    else {
                    ver=colisaoPredio(Hpredios, y, x);

                    if(ver==0)
                        break;}
            }

                refresh();

        }else{ //Vez jogador 2
            curs_set(1);
            mvprintw(2,110,"Angulo:");
            refresh();
            getstr(ang2);
            mvprintw(2,117,"%s",ang2);
            refresh();
            ang2n=atoi(ang2);

            mvprintw(3,110,"Velocidade:");
            refresh();
            getstr(vel2);
            mvprintw(3,121,"%s",vel2);
            refresh();
            vel2n=atoi(vel2);

            mvprintw(2,110,"                         ");
            mvprintw(3,110,"                         ");

            curs_set(0);
            refresh();

            //Lançamento
            float angRad2 = (ang2n*3.14)/180;
            double seno2 = sin(angRad2);
            double cose2 = cos(angRad2);
            float tempo2 = fabs(((2*vel2n)*(cose2))/g);


            for (float t=0; t < tempo2+10; t += 0.1) {
                int x2 = (126 - abs(vel2n) * cose2 * t); 
                int y2 = (Hpredios[7]-2) - (abs(vel2n) * (seno2) * t) + ((g*(t*t))/2); 
                
                mvprintw(y2,x2, "Z");
                refresh();
                usleep(100000);
                mvprintw(y2,x2, " ");   
                

            //macaco2 -> macaco1
                if ((y2 <= Hpredios[0]-1 && y2 >= Hpredios[0]-3) && (x2 >= 9 && x2 <= 12 )){
                    mvprintw(5, 5,"Voce acertou!");
                    break;
                } else if ((y2 >= Hpredios[7]) && (x2 >= 122 && x2 <= 127 )){ //predio do macaco 2
                    mvprintw(5, 5,"Errou!");
                    break;
                } else if (y2>= Hpredios[0] && (x2>=3 && x2 <=19)){ //inicio do primeiro predio
                    mvprintw(5, 5,"Errou!");
                    break;
                } else {
                    ver = colisaoPredio(Hpredios, y2, x2);

                    if(ver==0)
                        break;
                }

                refresh();

            }
        }

        controle=getch();
        noecho();
        if(controle=='q'){
            break;
        }

        vez++;
    }
    //delwin(predio);
return 0;
}