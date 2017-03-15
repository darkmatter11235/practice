#include "Snake.h"


void SnakeGui::regenerateFruit() {

    int newX = rand()%(width-2) + 1 ;
    int newY = rand()%(height-2) + 1;
    while( isOnSnake(newX, newY) && (newX != fruitX && newY != fruitY) ) {
        newX = rand()%(width-2) + 1 ;
        newY = rand()%(height-2) + 1;
    }
    fruitX = newX;
    fruitY = newY;
}

void SnakeGui::DrawCanvas() {
    //Draw the walls
    clear();
    char w = '#';
    char space = ' ';
    char fruit = 'O';
    char S = 'z';
    int Total = 10;
    int LevelNum = 1;

    for(int i = 0; i < height; i++) {
        if ( i == 0 || i == height-1 ) {
            for(int j = 0; j < width; j++) {
                printw("%c", w);
            }
            if ( i == 0 ) {
                printw("   Level: %d Need: %d", LevelNum, Total);
            }
        } else {
            printw("%c", w);
            for(int j = 0; j < width-2; j++) {
                if ( i == fruitY && j == fruitX ) {
                    printw("%c", fruit);
                } else if ( isOnSnake(j, i) ) {
                    printw("%c", S);
                } else {
                    printw("%c", space);
                }
            }
            printw("%c", w);
            if ( i == 1 ) {
                printw("   Score: %d ", numFruitsCaptured);
            }
        }
        printw("\n");
    }
}

bool SnakeGui::isOnSnake(int i, int j) {
    std::vector<position>::iterator it;
    for(it = snake.begin(); it != snake.end(); it++) {
        if ( it->first == i && it->second == j ) { return true; }
    }
    return false;
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
        case 'x':
            gameOver = true;
            break;
        default:
            break;
    }
    return ;
}

bool SnakeGui::GameOver() {
    if ( gameOver ) {
        return true;
    }
    return false;
}

bool SnakeGui::isTimeToMove() {
    struct timeval now;
    gettimeofday(&now, NULL);
    int ms = (now.tv_sec - lastMoveTime.tv_sec)*1000 + (now.tv_usec - lastMoveTime.tv_usec)/1000;
    if ( ms > moveThresholdTime) {
        lastMoveTime = now;
        return true;
    }
    return false;
}

void SnakeGui::UpdateCanvas() {


    int snakeX, snakeY;
    snakeX = snake[0].first;
    snakeY = snake[0].second;
    if ( isTimeToMove() ) 
    {

        switch(nextMove ) {
            case ML:
                snakeX--;
                break;
            case MR:
                snakeX++;
                break;
            case MU:
                snakeY--;
                break;
            case MD:
                snakeY++;
                break;
            default:
                return;
                break;
        }

        if ( snakeX == width-1 || snakeX == 0 || snakeY == height-1 || snakeY == 0 ) { gameOver = true; }

        if ( snakeX == fruitX && snakeY == fruitY ) { 
            position tail = snake.back();
            std::vector<position>::iterator it;
            for(it = snake.begin(); it != snake.end(); it++) {
                int curx = it->first;
                int cury = it->second;
                it->first = snakeX;
                it->second = snakeY;
                snakeX = curx;
                snakeY = cury;
            }

            snake.push_back(tail);
            numFruitsCaptured++;
            regenerateFruit();
        } else {
            std::vector<position>::iterator it;
            for(it = snake.begin(); it != snake.end(); it++) {
                int curx = it->first;
                int cury = it->second;
                it->first = snakeX;
                it->second = snakeY;
                snakeX = curx;
                snakeY = cury;
            }
        }

    }

}

int main(int argv, char** argc) {
    int cw, ch;
    cw = ch = 40;
    srand(time(NULL));
    SnakeGui sg(cw, ch);
    //newterm();
    initscr();
    raw();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    while(!sg.GameOver()) {
        sg.DrawCanvas();
        sg.GetUserInput();
        sg.UpdateCanvas();
        refresh();
    } 
    printw("Darrr! Goes the blow! \n");
    endwin();
    return 0;
}
