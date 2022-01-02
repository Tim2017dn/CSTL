//
// Created by dolly on 2022/1/2.
//

#ifndef BTREE_LIST_H
#define BTREE_LIST_H

typedef struct _node{
    struct _node* prev;
    struct _node* next;
}node_t;

typedef  struct _list{
    node_t* head;
    node_t* tail;
    int count;
}list_t;

void list_add_tail(list_t* list, node_t* node);

void list_init(list_t* list);


#endif //BTREE_LIST_H
