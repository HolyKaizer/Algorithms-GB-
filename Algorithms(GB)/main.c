
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

/*----------------------------------Домашняя работа номер 7.------------------------------*/


#define T int

typedef struct GraphNode {
    T data;
    int index;
    int used;
    struct List * childrens;
} GraphNode;

typedef struct NodeQ{
    GraphNode * data;
    struct NodeQ *next;
    struct NodeQ *prev;
} NodeQ;


typedef struct List{
    NodeQ * head;
    NodeQ * tail;
    int size;
} List;


T pushQueue(List *qu, GraphNode * value) {
    NodeQ * temp = (NodeQ*) malloc(sizeof(NodeQ));
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

GraphNode * popQueue(List *qu) {
    if (!qu->size) {
        return 0;
    }

    NodeQ * temp = qu->tail;

    GraphNode * result = temp->data;

    qu->tail = qu->tail->prev;
    qu->size--;
    free(temp);

    return result;
}
 

//Задание номер 1.
//    Написать рекурсивную функцию обхода графа в глубину.


typedef struct Node {
    GraphNode * data;
    struct Node *next;
} Node ;

typedef struct {
    Node *head;
    int size;
} Stack;

int push(Stack *st, GraphNode * val) {
    Node * temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) return 0;

    temp->data = val;
    temp->next = st->head;

    st->head = temp;
    st->size++;
    return 1;
}

GraphNode * pop(Stack *st) {
    Node * temp = st->head;

    st->head = st->head->next;
    st->size--;

    GraphNode * result = temp->data;
    free(temp);

    return result;
}


int depthTravers(GraphNode *start, GraphNode *stop, Stack * st) {
    
    push(st, start);
    start->used = 1;
    
    while (st->size != 0) {
        GraphNode * current = pop(st);
        
        if (current->data == stop->data) {
            return 1;
        }
        
        if (current->used == 0) {
            depthTravers(current, stop, st);
        }
    }
    return 0;
}



//Задание номер 2.
//    Написать функцию обхода графа в ширину.

GraphNode * getFromList(List * list, int idx) {
    NodeQ * current = list->head;

    while (current) {
        if (list->head->data->index == idx)
            return list->head->data;
        current = current->next;
    }
    
    return NULL;
}



int widthTravers(GraphNode *start, GraphNode *stop, List * q) {
    pushQueue(q, start);
    start->used = 1;
    
    int i = 0;
    while (q->size != 0) {
        
        GraphNode * current = popQueue(q);
        if (current->data == stop->data) {
            return 1;
        }
        
        while (current->childrens->size != 0) {
            if (getFromList(current->childrens, i)->used != 1) {
                pushQueue(q, getFromList(current->childrens, i));
                getFromList(current->childrens, i)->used = 1;
            }
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {

       
}

