
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
#define T int
#define ANSI 256

// Урок 6

typedef int hashTableIndex;
#define compEQ(a,b) (a == b)

struct Node_ {
    T data;
    struct Node_ *next;
};

typedef struct Node_ hNode;

hNode **hashTable;

int hashTableSize;

hashTableIndex hash(T data) {
    /************
     Хэш функция применяемая к данным
     ************/
    return (data % hashTableSize);
}

hNode *insertNodeIntohTable(T data ) {
    hNode *p, *p0;
    hashTableIndex bucket;
    
    /************
        Распределим узел для данных и вставим в таблицу
    ************/
    
    //Вставка узла в начало таблицы
    bucket = hash(data);
    p = (hNode*) malloc(sizeof(hNode));
    
    if (!p) {
        printf("Memory is FULL!");
    }
    
    p0 = hashTable[bucket];
    hashTable[bucket] = p;
    p->next = p0;
    p->data = data;
    return p;
}

//Построение балансного дерева с N кол-вом узлов
//
//Node * balanceTree(int n) {
//
//    Node * newNode;
//    int leftNodes, rightNodes;
//    T data;
//
//    if (!n)
//        newNode = NULL;
//    else {
//        scanf("%d", &data);
//        getchar();
//        leftNodes = n / 2;
//        rightNodes = n - leftNodes - 1;
//
//        newNode = (Node *) malloc(sizeof(Node));
//        newNode->data = data;
//        newNode->left = balanceTree(leftNodes);
//        newNode->right = balanceTree(rightNodes);
//    }
//
//    return newNode;
//}

//Храним дерево в массиве:
// а[0] = ROOT
// a[i*2 +1] = первый наследник(левое поддерево)
// a[i*2 + 2] = первый наследник(правое поддерево)




int main(int argc, const char * argv[]) {
    
    printf("Результат хэширование строки 'ASnsfasfa' - %lu", hashString("ASnsfasfa"));
    printf("\n");
       
}

