#include <stdio.h>
#include <curses.h>

int menu(void){

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

        while(true) {
                mvwprintw(janela, 10, 70, "GORILLAS");
                for(int i=0; i < 3; i++) {
                        if (i == index) {
                                wattron(janela, A_REVERSE);
                                mvwprintw(janela, i+15, 70, "%s", menu[i]);
                                wattroff(janela, A_REVERSE);
                        } else {
                                mvwprintw(janela, i+15, 70, "%s", menu[i]);
                        }
                }
                escolha = wgetch(janela);
				
        switch(escolha) {
                case KEY_UP:
                index--;
                if(index == -1)
                        index = 0;
                break;
                case KEY_DOWN:
                index++;
                if(index == 3) 
                        index = 2;
                break;
                case KEY_ENTER:
                //não funciona
                mvprintw(2, 7, "voce escolheu: %s",menu[escolha]);
                break;
                default:
                break;
                if(escolha == 10)
                        break;         
        }
		getch();
                endwin();
        }

}

int main(void){

        menu();
}
