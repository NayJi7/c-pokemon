#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
<<<<<<< HEAD
#include "../headers/game.h"
#include "../headers/structs.h"
=======
>>>>>>> 59f41b263d1e9ce35002547dec97413a6a0ace11

void printplayer(WINDOW* win,int x,int y){
    init_pair(1,COLOR_RED,COLOR_BLACK);
    wattron(win,COLOR_PAIR(1));
    wprintw(win,"o");
    wmove(win,x+1,y-1);
    wprintw(win,"/0\\");
    wmove(win,x+2,y);
    wprintw(win,"ll");
    wattroff(win,COLOR_PAIR(1));
}

<<<<<<< HEAD
void menu(){
    WINDOW* winmenu=newwin(LINES/1.5,COLS/1.5,0,0);
    int chmenu=ERR;
    while(chmenu!='i')
        {
            wclear(winmenu);
            box(winmenu,0,0);

            mvwin(winmenu,LINES/6,COLS/6);
            wrefresh(winmenu);
            chmenu=getchar();
            sleep(1/60);
=======
int main(){
    initscr();
    noecho();
    cbreak();
    start_color();
    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
    curs_set(0);

    if(has_colors()==FALSE){
        printf("Your terminal does not support colors");
        exit(1);
    }

    if(can_change_color()==FALSE){
        printf("Your terminal does not support color changing");
        exit(1);
    }

    int chinv=ERR,ch=ERR,x,y;
    WINDOW* map=newwin(LINES,COLS,0,0);
    WINDOW* menu=newwin(LINES/1.5,COLS/1.5,0,0);

    x=LINES/2-1;
    y=COLS/2;
    wmove(map,x,y);

    while(ch!='p'){
        box(map,0,0);
        ch=getch();
                
        switch (ch)
        {
        case 'z':
            wclear(map);
            x=x-1;

            if (x<=0)
            {
                x=x+1;
            }

            break;

        case 's':
            wclear(map);
            x=x+1;

            if (x>=LINES-3)
            {
                x=x-1;
            }

            break;

        case 'd':
            wclear(map);
            y=y+2;

            if (y>=COLS-2)
            {
                y=y-2;
            }

            break;

        case 'q':
            wclear(map);
            y=y-2;

            if (y<=0)
            {
                y=y+2;
            }
            
            break;
        
        case 'i':
            while(chinv!='i')
            {
                wclear(menu);
                box(menu,0,0);

                mvwin(menu,LINES/6,COLS/6);
                wrefresh(menu);
                chinv=getchar();
                sleep(1/60);
            }
            chinv=ERR;
>>>>>>> 59f41b263d1e9ce35002547dec97413a6a0ace11
        }
        chmenu=ERR;
}

<<<<<<< HEAD
void game(int* exit,int* x,int* y){
    WINDOW* map=newwin(LINES,COLS-1,0,0);

    int ch=ERR;

    wmove(map,*x,*y);

    box(map,0,0);
    ch=getch();
            
    switch (ch)
    {
    case 'z':
        wclear(map);
        *x=*x-1;

        if (*x<=0)
        {
            *x=*x+1;
        }
        break;

    case 's':
        wclear(map);
        *x=*x+1;

        if (*x>=LINES-4)
        {
            *x=*x-1;
        }
        break;

    case 'd':
        wclear(map);
        *y=*y+2;

        if (*y>=COLS-2)
        {
            *y=*y-2;
        }
        break;

    case 'q':
        wclear(map);
        *y=*y-2;

        if (*y<=0)
        {
            *y=*y+2;
        }
        break;
    
    case 'i':
        menu();
        break;
    
    case 'p':
        *exit=0;
        break;
=======
        wmove(map,x,y);
        printplayer(map,x,y);

        wrefresh(map);
        sleep(1/60);
>>>>>>> 59f41b263d1e9ce35002547dec97413a6a0ace11
    }

    wmove(map,*x,*y);
    printplayer(map,*x,*y);
    wrefresh(map);
    sleep(1/60);
}