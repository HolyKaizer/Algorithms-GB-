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
#include <string.h>

//Задание номер 1.
//    Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
void from_two_to_ten(int n, char * bin) {
    if (n)
        from_two_to_ten(n / 2, bin);
    else
        return;

    strcat(bin, (n % 2) ? "1" : "0");
    return;
   
        
}

//Задание номер 2.
//     Реализовать функцию возведения числа a в степень b:
//        *рекурсивно, используя свойство чётности степени.
int powRec(int base, int exp) {
    if (exp)
        if (exp % 2 )
            return base * powRec(base, exp - 1);
        else
            return powRec(base * base , exp / 2);
    else
        return 1;
}

//Задание номер 2.5 и 3 решил на бумаге, приложу в Pull Request-e

//Задание номер 3

void calc(int to, int from, int *count) { // From = 20, To = 3;
    
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

int calc_fixed(int from, int to) {  // From = 3, To = 20;
    if(from < to)
        return calc_fixed(from + 1, to) + calc_fixed(from << 1, to);
    else if (from == to)
        return 1;
    else
        return 0;
}

#endif /* homework_2_h */
