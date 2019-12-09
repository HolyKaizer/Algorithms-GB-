
//
//  main.c
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 02.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#include <stdio.h>
#include "homework-1.h"

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

int main(int argc, const char * argv[]) {
    //Вставить любую задачу из homework-1
    hanoi(3, 1, 2, 3);
    printf("\n");
    
}
