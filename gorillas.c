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
    return 0;
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
    return 0;
}

int colisaoPredio (int Hpredios [], int y, int x){ //verificação se bateu no segundo ou nos proxs até o sétimo prédio.
    if ((y>= Hpredios[1] && (x>=20 && x <=36))||(y>= Hpredios[2] && (x>=37 && x <=53))||(y>= Hpredios[3] && (x>=54 && x <=70))||
    (y>= Hpredios[4] && (x>=71 && x <=87))||(y>= Hpredios[5] && (x>=88 && x <=104))|| (y>= Hpredios[5] && (x>=88 && x <=104))||
    (y>= Hpredios[6] && (x>=105 && x <=121)))
    {
        mvprintw(5, 5,"Errou!");
        return 0;
    }

    return 1;
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
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);

        int h, hmacaco1, hmacaco2;
        int Hpredios[8];
        int c = 0;
        int ver;
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
        Hpredios [i] = h;

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
                double seno = sin(angRad); //calcular o sen com a função sin()
                double cose = cos(angRad);
                float tempo = fabs(((2*vel1n)*(cose))/g);
                

                for (float t=0; t < tempo+5; t += 0.1) {
                    int x = 11 + abs(vel1n) * (cose) * t; // x = abs(11 + vel1n * cose * t)
                    int y = (hmacaco1-2) - (abs(vel1n) * (seno) * t) + ((g*(t*t))/2); // y = (hmacaco1-1) - abs((vel1n * seno * t) + (g*(t*t))/2)

                    wattron(predio,COLOR_PAIR(2));                    
                    mvprintw(y,x, "Z");
                    wattroff(predio,COLOR_PAIR(2));
                    usleep(100000);
                    refresh();
                    
                    mvprintw(y,x, " ");
                    

                //colisão
                    if ((y >= hmacaco2-1 && y <= hmacaco2-3) && (x >= 128 && x <= 130 )){
                        mvprintw(5, 5,"Voce acertou!");
                        break;
                    } else if (y >= hmacaco1 && (x >= 12 && x <= 19 )){ // predio do macaco 1
                        mvprintw(5, 5,"Errou!");
                        break;
                    } else if (y>= Hpredios[6] && (x>=122 && x <=127)){ //inicio do oitavo predio
                        mvprintw(5, 5,"Errou!");
                        break;
                    }else
                        ver=colisaoPredio (Hpredios, y, x);

                        if(ver==0)
                            break;
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


                for (float t=0; t < tempo2+5; t += 0.1) {
                    int x2 = (126 - abs(vel2n) * cose2 * t); 
                    int y2 = (hmacaco2-2) - (abs(vel2n) * (seno2) * t) + ((g*(t*t))/2); 
                    
                    mvprintw(y2,x2, "Z");
                    refresh();
                    usleep(100000);
                    mvprintw(y2,x2, " ");   
                    

                //colisão
                    if ((y2 >= hmacaco1-1 && y2 <= hmacaco1-3) && (x2 >= 9 && x2 <= 11 )){
                        mvprintw(5, 114,"Voce acertou!");
                        break;
                    } else if (y2 >= hmacaco2 && (x2 >= 122 && x2 <= 127 )){ //predio do macaco 2
                        mvprintw(5, 113,"Errou!");
                        break;
                    } else {
                        ver=colisaoPredio (Hpredios, y2, x2);

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


        delwin(predio);
    return 0;
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
    return 0;
}



int main(void){

    menu();
}
