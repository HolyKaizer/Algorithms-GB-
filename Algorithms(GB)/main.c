
//
//  main.c
//  Algorithms(GB)
//
//  Created by Антон Кайзер on 02.12.2019.
//  Copyright © 2019 Антон Кайзер. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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
    Node * temp = st->head;
    
    st->head = st->head->next;
    st->size--;
    
    T result = temp->data;
    free(temp);
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    
}
