//
// Created by dolly on 2022/1/1.
//

#ifndef CSTL_CHAPTER1_H
#define CSTL_CHAPTER1_H
typedef struct _node{
    struct _node* prev;
    struct _node* next;
}node_t;

typedef  struct _list{
    node_t* first;
    node_t* tail;
    int count;
}list_t;

void list_add_tail(list_t* list, node_t* node);
void list_init(list_t* list)
#endif //CSTL_CHAPTER1_H
