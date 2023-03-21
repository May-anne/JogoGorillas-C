#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "global.h"

extern int Hpredios[8];

int throwBanana(int ang, int vel, int jogador) {
    float angRad, tempo;
    double seno, cosseno;
    int x, y, g, status;
    g = 10;

    angRad = ang*3.14/180;
    seno = sin(angRad);
    cosseno = cos(angRad);
    tempo = fabs(((2*vel)*cosseno)/g);

    for (float t = 0; t < tempo + 10; t += 0.1) {

        if(jogador == 1) {
            x = 11 + abs(vel) * cosseno * t; // x = abs(11 + vel1n * cose * t)
            y = (Hpredios[0]-2) - (abs(vel) * seno * t) + ((g*(t*t))/2); // y = (hmacaco1-1) - abs((vel1n * seno * t) + (g*(t*t))/2)
        }
        else {
            x = (126 - abs(vel) * cosseno * t); 
            y = (Hpredios[7]-2) - (abs(vel) * seno * t) + ((g*(t*t))/2); 
        }

        mvprintw(y, x, "(");
        refresh();
        usleep(100000);
        mvprintw(y, x, " ");

     if(jogador == 1){ //Colisões específicas do jogador 1
        if ((y <= Hpredios[7]-1 && y >= Hpredios[7]-3) && (x >= 128 && x <= 130 )){
            mvprintw(5, 5, "Voce acertou!");
            break;
        } else if(y>= Hpredios[7] && (x>=122 && x <=138)) {
            mvprintw(5, 5,"Errou!");
            break;
        }

        } else if(jogador == 2){ //Colisões específicas do jogador 2
        if (y >= Hpredios[0] && (x >= 3 && x <= 19)) {
            mvprintw(5, 5,"Errou!");
            break;
        }
        else if ((y <= Hpredios[0]-1 && y >= Hpredios[0]-3) && (x >= 9 && x <= 12 )){
            mvprintw(5, 5,"Voce acertou!");
            break;
        }
     }
    //Verificação de colisão no mapa
    if ((y>= Hpredios[1] && (x>=20 && x <=36))||(y>= Hpredios[2] && (x>=37 && x <=53))||
    (y>= Hpredios[3] && (x>=54 && x <=70))|| (y>= Hpredios[4] && (x>=71 && x <=87))||(y>= Hpredios[5] && (x>=88 && x <=104))|| 
    (y>= Hpredios[5] && (x>=88 && x <=104))|| (y>= Hpredios[6] && (x>=105 && x <=121)))
    {
        mvprintw(5, 5,"Errou!");
        break;

    } else if (x<2 || x>138 || y > 30){ //Ultrapassou os limites do mapa
        mvprintw(5, 5,"Errou!");
        break;
        }
    }
    return 0;
}
