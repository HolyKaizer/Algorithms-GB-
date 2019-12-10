
//
//  homework_1.h
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 02.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#ifndef homework_1_h
#define homework_1_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Номера заданий взяты из методички

//Задание номер 1.
//    Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
//    где m-масса тела в килограммах, h - рост в метрах.
void first_task() {
    
    printf("Введите пожалуйста рост в метрах: ");
    float height;
    scanf("%f", &height);
    
    printf("Введите пожалуйста вес в килограммах: ");
    float weight;
    scanf("%f", &weight);
    
    float index = weight / (height * height);
    printf("Индекс массы тела равен %.1f \n", index);
}

//Задание номер 2.
//    Найти максимальное из четырех чисел. Массивы не использовать.
void second_task() {
    int num1 = 214;
    int num2 = 1321;
    int num3 = 12;
    int num4 = 1244;
    
    int max_result = 0;
    
    if (num1 >= num2 && num1 >= num3 && num1 >= num4)
        max_result = num1;
    else if (num2 >= num1 && num2 >= num3 && num2 >= num4)
        max_result = num2;
    else if (num3 >= num1 && num3 >= num2 && num3 >= num4)
    max_result = num3;
    else if (num4 >= num1 && num4 >= num2 && num4 >= num3)
    max_result = num4;
    
    printf("Максимально число из четырех заданных - это %d\n", max_result);
}

//Задание номер 3.
//    Написать программу обмена значениями двух целочисленных переменных:
//        a. с использованием третьей переменной;
//        b. *без использования третьей переменной.

void swap_integers_temp(int *x, int *y) {
    int *temp = y;
    *y = *x;
    *x = *temp;
}

void swap_integers(int *x, int *y) {
    if (*x == *y) {
        return;
    }
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

//Задание номер 4.
//    Написать программу нахождения корней заданного квадратного уравнения.
void calculateScuareEquality(int a, int b, int c, float x1, float x2) {
    
    double desc = (a << 2) * (double)c - (double)b * (double)b;
    
    if (desc < 0)
        printf("Уравнение не имеет решений!\n");
    else if (desc == 0) {
        x1 = -1 * (float)b / (a << 1) ;
        x2 = x1;
        printf("Уравнение имеет одно решение %.2f\n", x1);
    } else {
        x1 = (-1 * (float)b + sqrt(desc)) / (a << 1) ;
        x2 =  (-1 * (float)b - sqrt(desc)) / (a << 1) ;
        printf("Уравнение имеет два решения - x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    
    
}

//Задание номер 5.
//    С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
void calculateSeason(int mounth) {
    if ((mounth > 0 && mounth < 3) || mounth == 12)
        printf("Это зима!");
    else if (mounth > 2 && mounth < 6)
        printf("Это весна!");
    else if (mounth > 5 && mounth < 9)
        printf("Это лето!");
    else if (mounth > 8 && mounth < 12)
        printf("Это осень!");
    else
        printf("В году 12 месяцев!");
}

//Задание номер 6.
//    Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
void age_output() {
    printf("Введите пожалуйста возраст(от 1 до 150 лет): ");
    int age;
    scanf("%d", &age);
    
    if (age % 10 >= 5 || age % 10 == 0 || (age % 100 > 9 && age % 100 < 21))
        printf("Вы ввели %d лет\n", age);
    else if (age % 10 == 1)
        printf("Вы ввели %d год\n", age);
    else
        printf("Вы ввели %d года\n", age);
}

//Задание номер 7.
//    С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
//    Требуется определить, относятся ли к поля к одному цвету или нет.

void is_same_color() {
    
    printf("Введите данные первой коордианты: \n");
    printf("x1 - ");
    unsigned short x1;
    scanf("%hd", &x1);
    printf("y1 - ");
    unsigned short y1;
    scanf("%hd", &y1);
    
    printf("Введите данные второй коордианты: \n");
    printf("x2 - ");
    unsigned short x2;
    scanf("%hd", &x2);
    printf("y2 - ");
    unsigned short y2;
    scanf("%hd", &y2);
    
    
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        printf("Шахматы находятся на одинаковом цвете!\n");
    } else {
        printf("Шахматы находятся на разных цветах!\n");
    }

}

//Задание номер 8.
//    Ввести a и b и вывести квадраты и кубы чисел от a до b.
void task_seven() {
    
    printf("Введите пожалуйста два числа: \n");
    
    int a;
    printf("a - ");
    scanf("%d", &a);
    
    int b;
    printf("b - ");
    scanf("%d", &b);
    
    if (a > b)
        swap_integers(&a, &b);
    
    for(; a <= b; a++) {
        printf("Число = %d; Квадрат = %d; Куб = %d\n\n", a, a * a, a * a * a);
    }
    
}

//Задание номер 9.
//    Даны целые положительные числа N и K.
//    Используя только операции сложения и вычитания, найти частное от деления нацело N на K,
//    а также остаток от этого деления.

void nine_task() {
    printf("Введите целые положительные числа: \n");
    
    int n;
    printf("N - ");
    scanf("%d", &n);
    
    int k;
    printf("K - ");
    scanf("%d", &k);
    
    int quot = 0;
    int rem = n;
    
    while (rem >= k) {
        rem -= k;
        quot++;
    }
    
    printf("Частное деления %d на %d равно %d\n", n, k, quot);
    printf("Остаток от деления %d на %d равен %d\n", n, k, rem);
}

//Задание номер 10.
//    Дано целое число N (> 0).
//    С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры.
//    Если имеются, то вывести True, если нет — вывести False

void ten_task() {
    printf("Введите целое положительное число: \n");

    int n;
    printf("N - ");
    scanf("%d", &n);
    
    int result = 0;
    
    while (n > 0) {
        result = n % 10;
        n /= 10;
        if (result % 2 == 1) {
            printf("В числе есть нечетная цифра\n");
            return;
        }
    }
    printf("В числе нет нечетных цифр\n");
}

//Задание номер 11.
//    С клавиатуры вводятся числа, пока не будет введен 0.
//    Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
void eleven_task() {
    printf("Введите числа (для преркащения ввода введите 8): \n");
    int num = 0;
    int sum = 0;
    unsigned short count = 0;
    
    while (1) {
        scanf("%d", &num);
        if (num == 8)
            break;

        if (num % 2 == 0 && num % 10 == 8 && num > 0) {
            sum += num;
            count++;
        }
    }
    
    printf("Среднее поло-ых чисел кончающихся на 8 \n");
    printf("Равно %.2f\n\n", (float)sum/count);
}


//Задание номер 12.
//    Написать функцию нахождения максимального из трех чисел.
int max_of_three(int n1, int n2, int n3) {
    if (n1 >= n2 && n1 >= n3)
        return n1;
    else if (n2 >= n1 && n2 >= n3)
        return n2;
    else
        return n3;
}

//Задание номер 13.
//    Написать функцию, генерирующую случайное число от 1 до 100.
//        • с использованием стандартной функции rand()
//        • без использования стандартной функции rand()

unsigned int rand_with_inner_func() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

//Собственный генератор написать не получилось (
/*-------------------------------TODO-----------------------------------------*/


//Задание номер 14.
//    Автоморфные числа.
//    Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
//    Например, 25 \ :sup: `2` = 625.
//    Напишите программу, которая вводит натуральное число N
//    И выводит на экран все автоморфные числа, не превосходящие N.

void automorphic_numbers() {
    printf("Введите целое положительное число: \n");

    int n;
    printf("N - ");
    scanf("%d", &n);
    
    for (int cur_num = 0; cur_num <= n; cur_num++) {

        int devider = 1;
        int square = cur_num * cur_num;
        int temp = cur_num;
        
        while (temp > 0) {
            devider *= 10;
            temp /= 10;
        }
        
        if (cur_num == square % devider)
            printf("Число \"%d\" является автоморфным! \nПотому что его квадрат равен \"%d\"\n\n", cur_num, square);
        
    }
}

#endif /* homework_1_h */
