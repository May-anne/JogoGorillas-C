#include <stdio.h>
#include <curses.h>

void menu(void){
    int xmax, ymax;
    char menu[3][10] = {"Playing", "Ranking", "Exit"};
    int index = 0;
    int escolha;


    initscr();
    noecho();
    getmaxyx(stdscr,ymax,xmax);

    WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
    box(janela,0,0);
    refresh();
    wrefresh(janela);

    keypad(janela, true);
    mvwprintw(janela, 10, (xmax/2)-4, "GORILLAS");
    while(true) {
        for(int i=0; i < 3; i++) {
            if (i == index) {
                wattron(janela, A_REVERSE);
                mvwprintw(janela, i+15, (xmax/2)-4, "%s", menu[i]);
                wattroff(janela, A_REVERSE);
            } else {
                mvwprintw(janela, i+15, (xmax/2)-4, "%s", menu[i]);
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
            case 10: //ENTER EM ASCII
                wclear(janela);
                clear();
                mvprintw( 2, 7, "voce escolheu: %s", menu[index]);
                break;
            default:
                break;
        }
        if(escolha == 10)
                break;
    }
    getch();
    endwin();


}

int main(void){

        menu();
}

