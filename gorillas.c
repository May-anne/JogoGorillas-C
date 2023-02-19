#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

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
  //else if(menu[index] == menu[1])
  //    ranking();
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

        int h;
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
        h = rand() %16+9;
        prefresh(predio, 0, 0, h, 2+c, 30, 18+c);
        c = c + 17;
        }

        wgetch(predio);
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

    if (dificuldade[index] == dificuldade[0]){
        ValorLevel = 30;
        play(ValorLevel);}
    else if (dificuldade[index] == dificuldade[1])
        ValorLevel = 25;
    else if (dificuldade[index] == dificuldade[2])
        ValorLevel = 20;
    printw("Voce escolheu: %s", dificuldade[index]);
}




int main(void){

    menu();
}


