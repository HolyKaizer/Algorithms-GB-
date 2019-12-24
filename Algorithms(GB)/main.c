
//
//  main.c
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 02.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int WIDTH = 9;
const int HEIGHT = 9;
const int WALL = -1;
const int BLANK = -2;

int len;
int grid[HEIGHT][WIDTH];
int pointX[WIDTH * HEIGHT];
int pointY[WIDTH * HEIGHT];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


int lee(int startX, int startY, int endX, int endY) {
    if(startX == endX && startY == endY) return 0;
    if (grid[startY][startX] == WALL || grid[endY][endX] == WALL ) return 0;
    
    int x, y, vect, dist, stop;
    dist = 0;
    grid[startX][startY] = dist;
    
    do {
        stop = 1;
        for (y = 0; y < HEIGHT; y++) {
            for (x = 0; x < WIDTH; x++) {
                if (grid[x][y] == dist) {
                    for (vect = 0; vect < 4; vect++) {
                        int nextX = x + dx[vect];
                        int nextY = y + dy[vect];
                        if (nextX >= 0 && nextX < WIDTH &&
                              nextY >= 0 && nextY < HEIGHT &&
                              grid[nextY][nextX] == BLANK) {
                            stop = 0;
                            grid[nextY][nextX] = dist + 1;
                        }
                    }
                }
            }
        }
        dist++;
    } while (!stop && grid[endY][endX] == BLANK);
    
    if (grid[endY][endX] == BLANK) return 0;
    
    len = grid[endY][endX];
    x = endX;
    y = endY;
    while (dist > 0) {
        pointY[dist] = y;
        pointX[dist] = x;
        dist--;
        for (vect = 0; vect < 4; vect++) {
            int nextX = x + dx[vect];
            int nextY = y + dy[vect];
            if (nextX >= 0 && nextX < WIDTH &&
                  nextY >= 0 && nextY < HEIGHT &&
                    grid[nextY][nextX] == BLANK) {
                y = nextY;
                x = nextX;
            }
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {

       
}

