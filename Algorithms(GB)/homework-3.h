//
//  homework-3.h
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 10.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#ifndef homework_3_h
#define homework_3_h


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define MAX 100

//Задание номер 1.
//     Попробовать оптимизировать пузырьковую сортировку.

void bubbleSortOptimized(int *a, int len) {
    int i;
    int j;
    int flag;
    for (i = 0; i < len; i++) {
        flag = 1;
        for (j = 0; j < len - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                swap_integers(&a[j], &a[j+1]);
                flag = 0;
            }
        }
        
        if (flag) {
            break;
        }
    }
}


//Задание номер 2.
//     Написать функции сортировки, которые возвращают количество операций.


int bubbleSortOptimizedCount(int *a, int len) {
    int i;
    int j;
    int flag;
    int count = 0;
    for (i = 0; i < len; i++) {
        flag = 1;
        for (j = 0; j < len - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                swap_integers(&a[j], &a[j+1]);
                flag = 0;
            }
            count++;
        }
        
        if (flag) {
            break;
        }
    }
    return count;
}


//Задание номер 3.
//    *Реализовать шейкерную сортировку.

void shakerSort(int *a, int len) {
    int left = 0;
    int right = len - 1;
    int flag;
    
    while (left < right) {
        int j;
        flag = 1;
        for (j = left; j < right; j++) {
            if (a[j] > a[j+1]) {
                swap_integers(&a[j], &a[j+1]);
                flag = 0;
            }
        }
        right--;
        
        if (flag) {
            break;
        }
        
        for(j = right; j > left; j--) {
            if (a[j] < a[j-1]) {
                swap_integers(&a[j], &a[j-1]);
                flag = 0;
            }
        }
        left++;
        
        if (flag) {
            break;
        }
    }
}


//Задание номер 4.
//    Реализовать линейный алгоритм поиска рекурсивной функцией.

int linearSearchRec(int *ar, int value, int left, int right) {
    
    if (right < 1) {
        return -1;
    } else if (value == ar[left]) {
        return left;
    } else if (value == ar[right]){
        return right;
    }
    
    return linearSearchRec(ar, value, left + 1, right - 1);
}


//Задание номер 5.
//    Реализовать сортировку подсчётом (Алгоритм со списком).
//    Только для положительных значений

void listSort(int *ar, int len) {
    
    int list[MAX + 1];
    
    int i;
    for (i = 0; i <= MAX; i++) {
        list[i] = 0;
    }
    
    int result[len];
    

    for(i = 0; i < len; i++)
        list[ar[i]]++;
    
    for (i = 1; i <= MAX; ++i)
           list[i] += list[i-1];
     
    
    for (i = 0; i < len; i++) {
        result[list[ar[i]]-1] = ar[i];
        --list[ar[i]];
    }
    
    for (i = 0; i < len; i++) {
        ar[i] = result[i];
    }
}



#endif /* homework_3_h */
