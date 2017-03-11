#include "Snake.h"

#include<iostream>
#include<cmath>
#include<cstdlib>

void SnakeGui::DrawCanvas() {
    //Draw the walls
    for(int i = 0; i < height; i++) {
        if ( i == 0 || i == height-1 ) {
            for(int j = 0; j < width; j++) {
                std::cout << "#";
            }
        } else {
            std::cout << "#";
            for(int i = 0; i < width-2; i++) {
                std::cout << "";
            }
            std::cout << "#";
        }
        std::cout << endl;
    }
}

void SnakeGui::GetUserInput() {
}

void SnakeGui::UpdateCanvas() {
}

int main(cha** argc, int argv) {
    SnakeGui sg = new SnakeGui();
    sg.DrawCanvas();
}
