
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

#define T char
//
//#define SZ 100
//T Stack[SZ];
//int idx = -1;
//
//void push(T i) {
//    if (idx < SZ) {
//        Stack[idx++] = 1;
//    } else {
//        printf("Stack overflow");
//    }
//}
//
//T pop() {
//    if(idx != -1) {
//        return Stack[idx--];
//    } else {
//        printf("Stack is empty");
//        return -1;
//    }
//}


//
//typedef struct Node {
//    T data;
//    struct Node *next;
//} Node ;
//
//typedef struct {
//    Node *head;
//    int size;
//} Stack;
//
//int push(Stack *st, T val) {
//    Node * temp = (Node*) malloc(sizeof(Node));
//    if (temp == NULL) return 0;
//
//    temp->data = val;
//    temp->next = st->head;
//
//    st->head = temp;
//    st->size++;
//    return 1;
//}
//
//T pop(Stack *st) {
//    Node * temp = st->head;
//
//    st->head = st->head->next;
//    st->size--;
//
//    T result = temp->data;
//    free(temp);
//
//    return result;
//}


typedef struct Node {
    T data;
    struct Node *next;
} Node ;

typedef struct {
    Node *head;
    int size;
} Stack;

int push(Stack *st, T val) {
    Node * temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) return 0;
    
    temp->data = val;
    temp->next = st->head;
    
    st->head = temp;
    st->size++;
    return 1;
}

T pop(Stack *st) {
    if (st->size == 0) {
        return -1;
    }
    Node * temp = st->head;
    
    st->head = st->head->next;
    st->size--;
    
    T result = temp->data;
    free(temp);
    
    return result;
}
/*------------------------------------Домащняя работа 5----------------------------------------*/
//Задание номер 1.
//    Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
void from_two_to_ten(int n, Stack *st) {
    while (n != 0) {
        if (n % 2)
            push(st, '1');
        else
            push(st, '0');
        n /= 2;
    }
}
//Задание номер 2.
//    Написать программу, которая определяет,
//    является ли введенная скобочная последовательность правильной.
//    Примеры правильных скобочных выражений: (), ([])(), {}(),
//    ([{}]),
//    неправильных — )(, ())({), (, ])}), ([(]) для скобок [, (, {.
//    Например: (2+(2*2)) или [2/{5*(4+7)}].
int correct_bracket_seq(char * str) {
    int i;
    Stack s;
    s.size = 0;
    s.head = NULL;
    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{')){ //Если скобка открывающая
            push(&s, str[i]);
        } else if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}')){ //Если скобка закрывающая
            T test = pop(&s);
            if (test == -1)
                return 0;
            else {                  //Если совпадают виды скобок - все верно, иначе плохая последовательность
                if ((test == '(') && (str[i] == ')'))
                    continue;
                else if ((test == '[') && (str[i] == ']'))
                    continue;
                else if ((test == '{') && (str[i] == '}'))
                    continue;
                else
                    return 0;
            }
        }
    }
    
    if (s.size) //Если стек остался пустым - последовательность закрылась, иначе остались открывающие скобки
        return 0;
    else
        return 1;
}

//Задание номер 3.
//    Создать функцию, копирующую односвязный список
//     (то есть создающую в памяти копию односвязного списка без удаления первого списка)
T top(Stack **top) {
    if((*top))
        return (*top)->head->data;
    else
        return 0;
}

Stack copy_stack(Stack * st) {
    Stack tempS;
    tempS.size = 0;
    tempS.head = NULL;
    
    Node * cur_pos = (Node*) malloc(sizeof(Node));
    cur_pos = st->head;

    while (cur_pos) {
        push(&tempS, cur_pos->data);
        cur_pos = cur_pos->next;
        tempS.size++;
    }
    
    Stack result;
    result.size = 0;
    result.head = NULL;
    
    while (tempS.size) {
        T item = pop(&tempS);
        tempS.size--;
        push(&result, item);
    }
    
    return result;
}


//Задание номер 4.
//    Реализовать очередь на двусвязном списке.
typedef struct Node2{
    T data;
    struct Node2 *next;
    struct Node2 *prev;
} Node2;

typedef struct {
    Node2 * head;
    Node2 * tail;
    int size;
} Queue;

int add(Queue *qu, T value) {
    Node2 * temp = (Node2*) malloc(sizeof(Node2));
    if (temp == NULL) return 0;
    
    temp->data = value;
    temp->next = qu->head;
    temp->prev = NULL;
    
    
    if (qu->head != NULL) {
        qu->head->prev = temp;
    } else {
        qu->tail = temp;
    }
    
    qu->head = temp;
    qu->size++;
    return 1;
}

T delete(Queue *qu) {
    if (!qu->size) {
        return -1;
    }
    
    Node2 * temp = qu->tail;
    
    T result = temp->data;
    
    qu->tail = qu->tail->prev;
    qu->size--;
    free(temp);
    
    return result;
}

int main(int argc, const char * argv[]) {
    Stack s;
    s.size = 0;
    s.head = NULL;

    /*-----------------Домащняя работа 5-------------*/
    
    /*-----Задание номер 1-----*/
    printf("\nЗадание номер 1:\n");
    from_two_to_ten(60, &s);
    while (s.size > 0) {
        printf("%c", pop(&s));
    }
    printf("\n");
    pop(&s);

    /*-----Задание номер 2-----*/
    printf("\nЗадание номер 2:\n");
    
    if(correct_bracket_seq("([{asfkjalsf}])"))
        printf("ВЕРНАЯ ПОСЛЕДОВАТЕЛЬНОСТЬ\n");
    else
        printf("НЕ ВЕРНАЯ ПОСЛЕДОВАТЕЛЬНОСТЬ\n");
    
    /*-----Задание номер 3-----*/
    printf("\nЗадание номер 3:\n");
    Stack s1;
    s1.size = 0;
    s1.head = NULL;
    push(&s1, '1');
    push(&s1, '2');
    push(&s1, '3');
    push(&s1, '4');
    push(&s1, '5');
    push(&s1, '6');
    push(&s1, '7');
    
    Stack s2 = copy_stack(&s1);
    
    printf("Резултат копии - ");
    while (s2.size > 0) {
        printf("%c", pop(&s2));
    }
    printf("\n");
    
    printf("Оригинальный стэк - ");
       while (s1.size > 0) {
           printf("%c", pop(&s1));
       }
       printf("\n");
    
    /*---Задание номер 4---*/
    printf("\nЗадание номер 4:\n");
    Queue q;
    q.size = 0;
    q.head = NULL;
    q.tail = NULL;
    
    add(&q, '1');
    add(&q, '2');
    add(&q, '3');
    add(&q, '4');
    add(&q, '5');
    
    while (q.size > 0) {
        printf("%c", delete(&q));
    }
    printf("\n");
    delete(&q);
    
    
}
