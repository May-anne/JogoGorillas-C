#include <stdio.h>
#include <curses.h>

int menu(void){

        int xmax, ymax;
        initscr();
        noecho();

        getmaxyx(stdscr,ymax,xmax);

        mvprintw((ymax/2),(xmax/2),"Hello World");

        WINDOW * janela = newwin((ymax-5),(xmax-5),2,2);
        box(janela,0,0);
        refresh();
        wrefresh(janela);

        getch();
        endwin();

        return 0;

}

int main(void){

        menu();



}
