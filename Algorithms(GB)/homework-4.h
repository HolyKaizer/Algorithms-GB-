//
//  homework-4.h
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 13.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#ifndef homework_4_h
#define homework_4_h


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define MAX 100

//Задание номер 1.
//    Количество маршрутов с препятствиями.
//    Реализовать чтение массива с препятствием и нахождение количество маршрутов.

int roots_with_obs(int x, int y, int obstacles[][10]) {
    if (x == 0 || y == 0)
        return 1;
    else if (obstacles[x][y])
        return roots_with_obs(x - 1, y, obstacles) +  roots_with_obs(x, y - 1, obstacles);
    else
        return 0;
}


//Задача номер 2.
//    Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

void print_2D_Array(int rows, int columns, char ar[][columns]) {
    int i;
    int j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++)
            printf("%3d", ar[i][j]);
        printf("\n");
    }
}

int matrix_lcs_length(char * A, char * B) {
    int i;
    int j;

    int strA = (int)strlen(A) + 1;
    int strB = (int)strlen(B) + 1;
    
    char substr[strA][strB];
    
    for (i = 0; i < strA; i++)
        for (j = 0; j < strB; j++)
            substr[i][j] = 0;
    
    for (i = 1; i < strA; i++) {
        for (j = 1; j < strB; j++) {
            if(A[i - 1] == B[j - 1] )
                substr[i][j] = 1 + substr[i - 1][j - 1];
            else
                substr[i][j] = max_of_three(substr[i - 1][j], substr[i][j - 1], 0);
        }
    }
    
    print_2D_Array(strA, strB, substr);
    return substr[strA - 1][strB - 1];
}


#endif /* homework_4_h */
