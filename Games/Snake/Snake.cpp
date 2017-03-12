#include "Snake.h"

#include<unistd.h>
#include<ncurses.h>
#include<term.h>

#include<iostream>
#include<cmath>
#include<cstdlib>


void SnakeGui::DrawCanvas() {
    //Draw the walls
    clear();
    char w = '#';
    char space = ' ';
    char fruit = 'O';
    char S = 'o';
    for(int i = 0; i < height; i++) {
        if ( i == 0 || i == height-1 ) {
            for(int j = 0; j < width; j++) {
                printw("%c", w);
            }
        } else {
            printw("%c", w);
            for(int j = 0; j < width-2; j++) {
                if ( i == fruitY && j == fruitX ) {
                    printw("%c", fruit);
                } else if ( i == snakeX && j == snakeY ) {
                    printw("%c", S);
                } else {
                    printw("%c", space);
                }
            }
            printw("%c", w);
        }
        printw("\n");
    }
}

void SnakeGui::GetUserInput() {
    int c;
    c = getch();
    switch(c) {
        case 'j':
            nextMove = ML;
            break;
        case 'l':
            nextMove = MR;
            break;
        case 'i':
            nextMove = MU;
            break;
        case 'k':
            nextMove = MD;
            break;
        default:
            nextMove = NM;
            break;
    }
    if ( nextMove != NM ) {
        
    }
    return ;
}

bool SnakeGui::GameOver() {
    if ( gameOver ) {
        return true;
    }
    return false;
}

void SnakeGui::UpdateCanvas() {

    switch(nextMove) {
        case ML:
            snakeX--;
            break;
        case MR:
            snakeX++;
            break;
        case MU:
            snakeY++;
            break;
        case MD:
            snakeY--;
            break;
        default:
            break;
    }
        
}

int main(int argv, char** argc) {
    int cw, ch;
    cw = ch = 40;
    SnakeGui sg(cw, ch);
    //newterm();
    initscr();
    raw();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    while(!sg.GameOver()) {
        sg.DrawCanvas();
        sg.GetUserInput();
        sg.UpdateCanvas();
        refresh();
    }
    endwin();
    return 0;
}
