//
//  homework-2.h
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 10.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#ifndef homework_2_h
#define homework_2_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Задание номер 1.
//    Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
void from_two_to_ten(int n) {
    if (n == 0) return;
    
    if (n % 2 == 1) {
        from_two_to_ten(n/2);
        printf("1");
    } else {
        from_two_to_ten(n/2);
        printf("0");
    }
        
}

//Задание номер 2.
//     Реализовать функцию возведения числа a в степень b:
//        *рекурсивно, используя свойство чётности степени.
int powRec(int base, int exp) {
    if (exp == 1)
        return base;
    
    if (exp % 2 == 0)
        return powRec(base * base , exp / 2);
    else
        return base * powRec(base, exp - 1);
}

//Задание номер 2.5 и 3 решил на бумаге, приложу в Pull Request-e

//Задание номер 3

void calc(int to, int from, int *count) {
    
    if (from < to)
        return;
    else if (from == to){
        *count = *count + 1;
        return;
    }
    
    if(from % 2 == 1)
        calc(to, from - 1, count);
    else {
        calc(to, from / 2, count);
        calc(to, from - 1, count);
    }
}
#endif /* homework_2_h */
