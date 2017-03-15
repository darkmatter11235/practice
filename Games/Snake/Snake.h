#ifndef GAMES_SNAKE_H
#define GAMES_SNAKE_H

#include<sys/time.h>
#include<unistd.h>
#include<ncurses.h>
#include<term.h>
#include<stdlib.h>

#include<vector>
#include<iostream>
#include<cmath>
#include<cstdlib>


enum MOVE {ML =0, MR, MU, MD, NM };
typedef struct timeval timeVal;
typedef std::pair<int, int> position;

class SnakeGui {
    public:
        SnakeGui(int w, int h): width(w), height(h) {
            position head = std::make_pair(w/2, h/2);
            snake.push_back(head);
            gameOver = false;
            regenerateFruit();
            gettimeofday(&lastMoveTime, NULL);
            moveThresholdTime = 200;
            nextMove = NM;
            numFruitsCaptured = 0;
        }
        void DrawCanvas();
        void GetUserInput();
        void UpdateCanvas();
        void regenerateFruit();
        bool GameOver();
        bool isTimeToMove();
        bool isOnSnake(int i, int j);
    private:
        int height;
        int width;
        int fruitX;
        int fruitY;
        std::vector<position> snake;
        int moveThresholdTime;
        timeVal lastMoveTime;
        bool gameOver;
        MOVE nextMove;
        int numFruitsCaptured;
};
#endif
