//
// Created by dolly on 2021/9/20.
//

#ifndef CSTL_COMMON_H
#define CSTL_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//#include "sortUtils.h"

typedef  struct{
    int num;
    char name[100];
} Item;

typedef struct _Node{
    Item* item;
    struct _Node* next;
} Node;


#endif //CSTL_COMMON_H
