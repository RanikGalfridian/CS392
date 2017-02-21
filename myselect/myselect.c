#include <ncurses.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

#define MAXHEIGHT 9

int HEIGHT = 0;
int WIDTH = 0;
int* highlight;
int currCol;
int args;
char** choices;

int n_choices;
void print_menu(WINDOW* menu_win, int underline);



int main(int argc, char* argv[]){
    WINDOW* menu_win;
    int underline = 1;
    int choice = 0;
    argc--;
    argv++;
    args = argc;
    highlight = (int*) malloc(sizeof(int) * argc);
    int row, col, c, i, j;

    /* Setup of the basic ncurses window */
    initscr();
    getmaxyx(stdscr, row, col);
    clear();
    noecho();
    cbreak();
    raw();
    menu_win = newwin(0, 0, 0, 0);
    keypad(menu_win, TRUE);
    refresh();

    choices = (char**) malloc(sizeof(char*) * argc);

    for(i = 0; i < argc; i++){
        highlight[i] = 0;
        choices[i] = argv[i];
    }


    n_choices = argc;
    HEIGHT = row;
    WIDTH = col;

    if(getenv("ESCDELAY") == NULL) ESCDELAY = 25;

    /*if(has_colors()){
        start_color();

        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
    }*/
    refresh();


    while(1){
        print_menu(menu_win, underline);

        c = wgetch(menu_win);
        switch(c){
            case KEY_UP:
                if(underline == 1) underline = n_choices;
                else --underline;
                break;
            case KEY_DOWN:
                if(underline == n_choices) underline = 1;
                else ++underline;
                break;
            case KEY_LEFT:
                if(underline < 10) underline = 1;
                else underline -= 10;
                break;
            case KEY_RIGHT:
                if( (underline <= n_choices) && (underline >= (n_choices - 10)) ) underline = n_choices;
                else underline += 10;
                break;
            case 27:
                choice = underline;
                break;
            case 10:
                choice = underline;
                clear();
                endwin();
                for(j = 0; j < n_choices; j++){
                    if(highlight[j])
                        printf("%s ", choices[j]);
                }
                printf("\n");
            case ' ':
                if(highlight[underline - 1] == 0) {
                    highlight[underline - 1] = 1;

                    if(underline == n_choices) underline = 1;
                    else ++underline;
                }
                else highlight[underline - 1] = 0;
                break;
            case KEY_RESIZE:
                clear();
                getmaxyx(stdscr, row, col);
                HEIGHT = row;
                WIDTH = col;
                refresh();
            default:
                refresh();
                break;
        }
        if(choice != 0) break;
    }

    refresh();
    endwin();
    return 0;
}

void print_menu(WINDOW* menu_win, int underline){
    int x = 0, y = 0, i, j = 0, maxlength = 0;
    int canDraw = 1;
    int argL = 0;
    currCol = 0;

    while(argL < args){
        y = 0;
        maxlength = 0;

        while(y < HEIGHT && argL < args){
            if(strlen(choices[argL]) > maxlength) { maxlength = strlen(choices[argL]); }
            y++;
            argL++;
        }
        if(maxlength + x > WIDTH){
            canDraw = 0;
            mvwprintw(menu_win, 0, 0, "Please enlarge the screen.");
        }else{
            canDraw = 1;
        }
        x += maxlength+2;
    }
    x=0;
    y=0;
    if(canDraw){
        for(i = 0; i < n_choices; ++i){
            if(underline == i + 1){
                wattron(menu_win, A_UNDERLINE);
                mvwprintw(menu_win, y, x, "%s", choices[i]);
                wattroff(menu_win, A_UNDERLINE);
            }else
                mvwprintw(menu_win, y, x, "%s", choices[i]);

            if(highlight[i] == 1){
                wattron(menu_win, A_STANDOUT);
                mvwprintw(menu_win, y, x, "%s", choices[i]);
                wattroff(menu_win, A_STANDOUT);
            }
            if(y <= HEIGHT)
                ++y;
            else if (y > HEIGHT) {
                for(j = 0; j < HEIGHT; j++){ 
                    if(strlen(choices[j + (HEIGHT * currCol)]) > maxlength){ maxlength = strlen(choices[j + (HEIGHT * currCol)]); } 
                }
                currCol++;
                y = 0;
                x += (maxlength + 2);
            }
        }
    }
    wrefresh(menu_win);
}

