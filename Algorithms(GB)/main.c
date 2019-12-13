
//
//  main.c
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 02.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#include <stdio.h>
#include "homework-1.h"
#include "homework-2.h"
#include "homework-3.h"
#include "homework-4.h"

int GCD(int x, int y) {
    
    while (x != y) {
        if(x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}

int GCD_Fast(int x, int y) {
    
    while(y != 0) {
        int z = x % y;
        x = y;
        y = z;
    }
    return x;
}

float Average(int n) {
    float sum = 0;
    int counter = 0;
    
    while (counter < n) {
        int in;
        scanf("%d", &in);
        sum += in;
        counter++;
    }
    return sum / (float) n;
}

void Mean() {
    printf("Программа по подсчету среднего значения положительных чисел\n");
    printf("Чтобы закончить ввод, введите -1\n");
    int counter = 0;
    float sum = 0;
    int in;
    
    do {
        scanf("%d", &in);
        sum += in;
        counter++;
        
    } while (in != -1);
    
    if (sum != -1) {
        printf("Среднее значение введенных чисел равно: %.2f\n", (float)(sum / counter));
    } else {
        printf("Не было введенно ни одного значения");
    }
}
int Turn(int in) {
    int result = 0;
    while (in > 0) {
        result *= 10;
        result += in % 10;
        in /= 10;
    }
    return result;
}

int Power_Fast(int base, int sign) {
    int result = 1;
    
    while (sign != 0) {
        
        if (sign % 2) {                //Odd
            result  *= base;
            sign--;
        } else {            // Even
            sign /= 2;
            base *= base;
        }
    }
    
    return result;
}


/*--------------------------------------Lesson 2----------------------------------------*/

void cycle(int a, int b) {
    while (a < b) {
        printf("%d ", a);
        a++;
    }
    printf("%d ",a);
}

void loop(int a, int b) {
    printf("%d ", a);
    a++;
    if (a < b) {
        loop(a, b);
    }
    printf(" r%d",a);
}

int Fc(int n) {
    int result = 1;
    while (n > 0) {
        result *= n--;
    }
    return result;
}

int FcRec(int n) {
    if (n < 2)
        return 1;
    else
        return n * FcRec(n - 1);
}

void hanoi(int numbersOfRing, int fromColumn, int toColumn, int tempColumn) {
    if (numbersOfRing != 0) {
        hanoi(numbersOfRing - 1, fromColumn, tempColumn, toColumn);
        printf("%d -> %d\n", fromColumn, toColumn);
        hanoi(numbersOfRing - 1, tempColumn, toColumn, fromColumn);
    }
}

/*--------------------------------------Lesson 3----------------------------------------*/

void printArray(int *a, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("[%d] ", a[i]);
    }
    printf("\n");
}


void fillArray(int * a, int len) {
    int i;
    for (i = 0; i < len; i++) {
        a[i] = rand() % 100;
    }
}



int lenearSearch(int *a, int len, int value) {
    int i = 0;
    while (i < len && a[i] != value) i++;
    return (i == len) ? -1 : i;
}


void bubbleSort(int *a, int len) {
    int i;
    int j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len - 1; j++) {
            if (a[j] > a[j+1]) {
                swap_integers(&a[j], &a[j+1]);
            }
        }
    }
}


void pickSort(int* a, int len) {
    int i;
    int j;
    
   for (i = 0; i < len; i++) {
       int flag = i;
       for (j = i + 1; j < len; j++) {
           if (a[j] < a[flag]) {
               flag = j;
           }
        swap_integers(&a[i], &a[flag]);
       }
   }
}


int binarySearch(int *a, int len, int value) {
    int left = 0;
    int right = len - 1;
    int middle = (right + left) / 2;
    
    while (left < right && a[middle] != value) {
        if (a[middle] < value)
            left = middle + 1;
        else
            right = middle;
        middle = (right + left) / 2;
    }
    
    return(a[middle] == value ? middle : -1);
}


/*--------------------------------------Lesson 4----------------------------------------*/

#define X 8
#define Y 8

#define QUEENS 8

int board[Y][X];

int routes(int x, int y) {
    if(x == 0 || y == 0)
        return 1;
    else
        return routes(x - 1, y) + routes(x, y - 1);
}

void annul() {
    int i;
    int j;
    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard() {
    int i;
    int j;
    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
}

int checkQueen(int x, int y) {
    int i;
    int j;
    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            if (board[i][j] != 0) { //Если нашли фигуру
                if (!(i == x && j == y)) {  //Если нашли не нашу фигуру
                    // Лежат на одной вертикали
                    if (i - x == 0 || j - y ==0) return 0;

                    //Лежат на одной диагонали
                    if (abs(i - x) == abs(j - y)) return 0;
                }
            }
        }
    }
    //Если дошли сюда, то все в порядке
    return 1;
}

int checkBoard() {

    int i;
    int j;
    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            if (board[i][j] != 0) {
                if (checkQueen(i, j) == 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}


int queens(int n) {
    
    if(checkBoard() == 0) return 0;
    
    if (n == QUEENS + 1) return 1;
    
    int row;
    int col;
    
    for (row = 0; row < Y; row++) {
        for (col = 0; col < X; col++) {
            if (board[row][col] == 0) {
                board[row][col] = n;
                
                if (queens(n+1) )
                    return 1;
                board[row][col] = 0;
            }
        }
    }
    return 0;
}


/*---------------------ЗАДАНИЕ НОМЕР 3. Домашняя работа 4.----------------------*/
//    Требуется обойти конем шахматную доску размером NxM,
//    пройдя через все поля доски по одному разу.
//    Здесь алгоритм решения такой же, как в задаче о 8 ферзях.
//    Разница только в проверке положения коня.


int checkKnights(int n) {
    int i;
    int j;
    int prevX = 0;
    int prevY = 0;
    n--; // Уменьшаем значение n для того, чтобы глубина просчета была два шага.
    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            if (board[i][j] == n-1) { //Если нашли прошлый ход
                if (n == 1) return 1;
                prevX = i;
                prevY = j;
            }
        }
    }
    
    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            if (board[i][j] == n) { // Нашли нынешний ход
                if ((abs(prevY - j) == 2 && abs(prevX - i) == 1) || (abs(prevX - i) == 2 && abs(prevY - j) == 1)) {
                    return 1;
                }
            }
        }
    }
    
    //Если дошли сюда, то расположение предыдущех двух коней не правильное
    return 0;
}

int knight_steps(int n) {
    
    if (n > 2)
        if(checkKnights(n) == 0) return 0;
    
    if (n == 65) return 1;
    
    int row;
    int col;
    
    for (row = 0; row < Y; row++) {
        for (col = 0; col < X; col++) {
            if (board[row][col] == 0) {
                board[row][col] = n;
                
                if (knight_steps(n+1))
                    return 1;
                
                board[row][col] = 0;
            }
        }
    }
    return 0;
}



#define SIZE 10
int main(int argc, const char * argv[]) {
    
    /*---------------------------------Homework 4--------------------------------------------*/
    
    //Задание 1.
    printf("\n Задание номер 1. \n");
    printf("Для изменения препятсвий, скоректируйте массив obstacles снизу \n");
    int i;
    int j;
    int obstacles[SIZE][SIZE] =
    {
        {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
        {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
        {  1,  1,  1,  0,  1,  1,  1,  1,  1,  1},
        {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
        {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
        {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
        {  1,  1,  1,  1,  1,  1,  0,  1,  1,  1},
        {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
        {  1,  1,  1,  0,  1,  1,  1,  1,  1,  1},
        {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1}
    };
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%7d", roots_with_obs(i, j, obstacles));
        }
        printf("\n");
    }
    
    //Задание 2.
    printf("\n Задание номер 2. \n");
    printf("Maximum lcs = %d",  matrix_lcs_length("GEEKBRAINS", "GEEKMINDS"));
    printf("\n\n");
    
    //Задание номер 3
    printf(" Задание номер 3.......Подождите пожалуйста (: \n");
    annul();
    knight_steps(1);
    printf("\nЗадача замещения конем была разрешена показанным на консоли маршрутом: \n");
    printBoard();
    printf("\nСпасибо за ожидание!! Задачка решилась!\n");
    printf("\n\n");
    return 0;
    
}
