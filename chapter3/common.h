//
// Created by dolly on 2021/9/20.
//

#ifndef CSTL_COMMON_H
#define CSTL_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "../chapter1/Queue.c"
//#include "../chapter1/common.h"

//#include "sortUtils.h"

typedef  struct{
    int num;
    char name[100];
} Item;

typedef struct _Node{
    Item* item;
    struct _Node *left;
    struct _Node *right;
    int size;
} Node;


#endif //CSTL_COMMON_H
