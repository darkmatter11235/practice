#ifndef GAMES_SNAKE_H
#define GAMES_SNAKE_H

enum MOVE {ML =0, MR, MU, MD, NM };
class SnakeGui {
    public:
        SnakeGui(int w, int h): width(w), height(h) {
            snakeX = w/2;
            snakeY = h/2;
            gameOver = false;
        }
        void DrawCanvas();
        void GetUserInput();
        void UpdateCanvas();
        bool GameOver();
    private:
        int height;
        int width;
        int snakeX;
        int snakeY;
        int fruitX;
        int fruitY;
        bool gameOver;
        MOVE nextMove;
};
#endif
