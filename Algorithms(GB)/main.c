
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

/*----------------------Домашняя работа номер 7. Исправленная ---------------------------*/

#define maxHeight 25
#define maxWidth 25
int matrix[maxHeight][maxWidth];

typedef struct GraphNode {
    int value;
    int index;
    int isChecked;
    struct GraphNode* qnext;
    struct GraphNode* qprev;
} GraphNode;

void readMatrixSize(FILE* f, int* width, int* height) {
    int lines = 0;
    int commas = 0;
    int max = 0;
    while (!feof(f)) {
        char c;
        fscanf(f, "%c", &c);
        if (c == ',')
            commas++;

        if (c == '\n') {
            lines++;
            if (commas > max)
                max = commas;
            commas = 0;
        }
    }
    *height = lines + 1;
    *width = max + 1;
}

void readMatrix(FILE* f, int size) {
    int i = 0, j = 0;
    while(!feof(f)) {
        char c;
        fscanf(f, "%d%c", &matrix[i][j], &c);
        j++;
        if (c == '\n' || c == '\r') {
            j = 0;
            i++;
        }
    }
}

void printMatrix(int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

typedef struct Queue {
    GraphNode* head;
    GraphNode* tail;
    int size;
} Queue;

void qPush(Queue* q, int value){
    GraphNode* tmp = (GraphNode*) malloc(sizeof(GraphNode));
    if (tmp == NULL){
        printf("Not enough memory\n");
        return;
    }
    tmp->qnext = q->head;
    tmp->qprev = NULL;
    tmp->value = value;
    tmp->index = q->size;
    if (q->head == NULL){
        q->tail = tmp;
    }
    else{
        q->head->qprev = tmp;
    }
    q->head = tmp;
    q->size++;

}

int qPop(Queue* q){
    if (q->size == 0){
        printf("empty stack\n");
        return -1;
    }
    int value = q->tail->value;
    GraphNode* tmp = q->tail;
    q->tail = q->tail->qprev;
    if (q->size > 1){
        q->tail->qnext = NULL;
    }
    else{
        q->head = NULL;
    }
    q->size--;
    free(tmp);

    return value;
}

int isChecked[maxWidth] = {0};
int depthTravers(int start, int goal, int size) {
    if (start == goal || isChecked[start]) {
        return 1;
    } else {
        isChecked[start] = 1;
        int j;
        for (j = 0; j < size; j++)
            if (matrix[start][j] == 1 && isChecked[j] == 0)
                return depthTravers(j, goal, size);
    }
    return 0;
}

Queue q;
int used[maxWidth] = {0};
int widthTravers(int start, int goal, int size){
    qPush(&q, start);
    int steps = 0;
    while (q.size > 0) {
        int value = qPop(&q);
        if (used[value] == 1) continue;
        used[value] = 1;
        steps++;
        if (value == goal)
            return steps;

        int i;
        for (i = 0; i < size; i++){
            if (matrix[value][i] == 1 && used[i] == 0)
                qPush(&q, i);

        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {

       
}

