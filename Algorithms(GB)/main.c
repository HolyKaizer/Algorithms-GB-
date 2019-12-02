
//
//  main.c
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 02.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#include <stdio.h>

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

int main(int argc, const char * argv[]) {
    //Вставить любую задачу из homework-1
}
