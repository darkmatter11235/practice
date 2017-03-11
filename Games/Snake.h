#ifndef GAMES_SNAKE_H
#define GAMES_SNAKE_H
class SnakeGui {
    public:
        SnakeGui(int w, int h): width(w), height(h) {
            sx = w/2;
            sy = h/2;
        }
        void DrawCanvas();
        void GetUserInput();
        void UpdateCanvas();
    private:
        int height;
        int width;
        int sx;
        int sy;
        int fruitX;
        int fruitY;
};
#endif
