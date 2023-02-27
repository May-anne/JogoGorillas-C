#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

int xmax, ymax;
int escolha, ValorLevel;

int mudarCor(char x[3][10], char y[]) //mudar cor ao usar setas down e up
{
    int index = 0;
    getmaxyx(stdscr,ymax,xmax);
    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    keypad(janela, true);
    mvwprintw(janela, 10, (xmax/2)-5, "%s", y);

    while(true) {
        for(int i=0; i < 3; i++) {
            if (i == index) {
                wattron(janela, A_REVERSE);
                mvwprintw(janela, i+15, (xmax/2)-4, "%s", x[i]);
                wattroff(janela, A_REVERSE);
            } else {
                mvwprintw(janela, i+15, (xmax/2)-4, "%s", x[i]);
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

int ranking (){

    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    mvwprintw(janela, 10, (xmax/2)-5, "RANKING DOS JOGADORES");

}

int menu(void){
    char menu[3][10] = {"Playing", "Ranking", "Exit"};
    char titulo[] = {"GORILLAS"};
    int picklevel (void);

    initscr();
    noecho();
    curs_set(0);

    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);
    int index = mudarCor(menu, titulo);

    if (menu[index] == menu[0])
        picklevel();
    else if(menu[index] == menu[1])
        ranking();
    else if (menu[index] == menu[2])
        endwin();

    getch();
    endwin();
}


int play(int nivel){
        initscr();
        clear();
        refresh();

        WINDOW * janela = newwin(32, 140, 0, 0);
        box(janela,0,0);
        refresh();
        wrefresh(janela);

        WINDOW * predio;
        predio = newpad(31,155);

        scrollok(predio, true);
        start_color();
        init_pair(1, COLOR_BLACK, COLOR_BLUE);

        int h, hmacaco1, hmacaco2;
        int c = 0;
        srand(time(NULL));

        for(int i = 0; i < 100; i++){
            for (int j = 0; j < 50; j++) {
                wattron(predio, COLOR_PAIR(1));
                pechochar(predio, '*');
                wattroff(predio, COLOR_PAIR(1));
            }
        }

        for (int i = 0; i < 8; i++) {

        h = 25 - (rand() %nivel);
        prefresh(predio, 0, 0, h, 2+c, 30, 18+c);

        if(i==0){

            //Macaco 1
            mvprintw(h-3,(c+8)," o");
            mvprintw(h-2,(c+8),"/|\\");
            mvprintw(h-1,(c+8),"/ \\");
            refresh();
            hmacaco1 = h;

        }else if(i==7){

            //Macaco 2
            mvprintw(h-3,(c+8)," o");
            mvprintw(h-2,(c+8),"/|\\");
            mvprintw(h-1,(c+8),"/ \\");
            refresh();
            hmacaco2 = h;
        }

        c = c + 17;
        }


        char jogador1[10];
        char jogador2 [20];
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
                    mvprintw(1,1,"Nome Jogador 1: ");
                    getstr(jogador1);
                    mvprintw(1,110,"Nome Jogador 2: ");
                    getstr(jogador2);

                    //Imprime nomes na tela
                    mvprintw(1,17,"%s",jogador1);
                    mvprintw(1,126,"%s",jogador2);

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
                //double seno = sin(angRad); calcular o sen com a função sin()
                //double cose = cos(angRad);
                float tempo = abs(((2*vel1n)*(-0.98))/g);

                //colisão
                for (float t=0; t < tempo ; t += 0.1) {

                    int x = 11 + abs(vel1n) * (0.15) * t; // x = abs(11 + vel1n * cose * t)
                    int y = (hmacaco1-2) - abs((vel1n * (-0.98) * t) + (g*(t*t))/2); // y = (hmacaco1-1) - abs((vel1n * seno * t) + (g*(t*t))/2)

                    mvprintw(y,x, "Z");
                    //sleep(5);
                    //mvprintw(y,x, " ");

                    for (int t = 0; t < 8; t++){
                        if ((y >= hmacaco2-1 && y <= hmacaco2-3) && (x >= 128 && x <= 130 )){
                        mvprintw(5, 5,"Voce acertou!");
                        break;
                    }
                    refresh();

                }
                }

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

                //Lançamentp
                float angRad2 = (ang2n*3.14)/180;
                //double seno2 = sin(angRad2); calcular o sen com a função sin()
                //double cose2 = cos(angRad2);
                float tempo2 = abs(((2*vel2n)*(-0.98))/g);

                //colisão
                for (float t=0; t < tempo2 ; t += 0.1) {

                    int x2 = 126 - abs(vel2n) * (0.15) * t; // x = abs(126 - vel2n * cose2 * t)
                    int y2 = (hmacaco2-2) - (abs(vel2n) * (-0.98) * t) + ((g*(t*t))/2); // y = (hmacaco2-1) - abs((vel2n * seno2 * t) + (g*(t*t))/2)

                    mvprintw(y2,x2, "Z");
                    //sleep(5);
                    //mvprintw(y2,x2, " ");

                    for (int k = 0; k < 8; k++){
                        if ((y2 >= hmacaco1-1 && y2 <= hmacaco1-3) && (x2 >= 9 && x2 <= 11 )){
                        mvprintw(5, 114,"Voce acertou!");
                        break;
                    }
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


        delwin(predio);

}
int picklevel (void)
{
    char dificuldade[3][10] = {"Facil", "Normal", "Dificil"};
    char titulo[] = {"ESCOLHA UMA DIFICULDADE"};

    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);


    int index = mudarCor(dificuldade, titulo);

    if (dificuldade[index] == dificuldade[0])
        ValorLevel = 5;
    else if (dificuldade[index] == dificuldade[1])
        ValorLevel = 10;
    else if (dificuldade[index] == dificuldade[2])
        ValorLevel = 15;
    play(ValorLevel);

}



int main(void){

    menu();
}
