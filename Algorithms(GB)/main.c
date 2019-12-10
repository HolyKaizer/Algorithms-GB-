
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

//Lesson 2
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

int main(int argc, const char * argv[]) {
//    Задача номер 1
//    char binary[64] = "b_";
//    from_two_to_ten(15, binary);
//    printf("Число 15 в двоичной системе равно %s", binary);
//    printf("\n");
    
    //Задача номер 2
//    printf("5 в степени 3 равно  - %d\n", powRec(5, 3));
    
    //Задание номер 3.
//    int count = 0;
//    calc(3, 20, &count);
//    printf("Варианты попадания из 20 в 3 равно - %d\n", count);
    const int SIZE = 10;
    int array[SIZE];
    fillArray(array, SIZE);
    printArray(array, SIZE);
    
    printf("Linear search: %d \n", lenearSearch(array, SIZE, 23));
    
    pickSort(array, SIZE);
    printArray(array, SIZE);
    
    printf("Binary search: %d \n", binarySearch(array, SIZE, 12));
    return 0;
}
