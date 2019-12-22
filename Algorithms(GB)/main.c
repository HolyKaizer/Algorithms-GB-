
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




/*-------------------------------Домащняя работа 6----------------------------------------*/

//Задание номер 1.
//    Реализовать простейшую хэш-функцию. На вход функции подается строка,
//    на выходе сумма кодов символов.

unsigned long hashString(char * str) {
    int length = (int)strlen(str);
    unsigned long resultHash = 0;
    
    
    for (int i = 0; i < length ; i++) {
        resultHash += (unsigned long)str[i];
    }

    return resultHash;
}


// Задание номер 2.
//    2. Написать программу, реализующую двоичное дерево поиска.
//
//        а) Добавить в него обход дерева различными способами;
//        б) Реализовать поиск в двоичном дереве поиска;
//        в) Добавить функцию вставки одного узла в дерево


//Структура узла дерева
typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;



//Задание 2.а.

// Обход дерева в прямом порядке
void preOrderTravers(Node *root) {
    if (root) {
        printf("%c", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

// Симметричный обход дерева
void inOrderTravers(Node *root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%c", root->data);
        inOrderTravers(root->right);
    }
}

// Обход в обратном порядке
void postOrderTravers(Node *root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%c", root->data);
    }
}


//Задание 2.б.

Node *searchNode(Node *root, T value) {
    while (root) {
        if (root->data < value) {
            root = root->left;
        } else if (root->data < value) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}


//Задание 2.в.

//Получение нового элемента в дереве
Node* getNewNode(T value, Node *parent) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

Node* getMinNode(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* getMaxNode(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Вставление нового элемента в дерево
void insertNode(Node **head, int value) {
    Node *tmp = NULL;
    
    if (*head == NULL) {
        *head = getNewNode(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
            } else {
                tmp->right = getNewNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
            } else {
                tmp->right = getNewNode(value, tmp);
                return;
            }
        } else {
            printf("Одинаковые элементы в дереве недопустимы!");
            return;
        }
    }
    
}

//Вывод дерева в консоль в виде скобоной последовательности
void printTree(Node * root) {
    if (root) {
        printf("%c", root->data);
        
        if (root->left || root->right) {
            
            printf("(");
            
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            
            printf(",");
            
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            
            printf(")");
        }
    }
}



int main(int argc, const char * argv[]) {
    
    printf("Результат хэширование строки 'ASnsfasfa' - %lu", hashString("ASnsfasfa"));
    printf("\n");
       
}

