//
// Created by dolly on 2022/1/1.
//
#include "common.h"
#include "chapter1.h"

void list_add_tail(list_t* list, node_t* node)
{
    if(list->first == NULL){
        list->first = node;
        list->tail = node;
        list->count++;
    }else{
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
        list->count++;
    }
}

void list_init(list_t* list)
{
    list->first = NULL;
    list->tail = NULL;
    list->count = 0;
}

typedef struct {
    node_t node;
    int age;
} student_t;

typedef struct {
    list_t list;
    int count;
} class_t;

int main(){
    class_t cla;
    student_t t1,t2,t3;
    t1.age = 1;
    t2.age = 2;
    t3.age = 3;
    list_init(&cla.list);
    list_add_tail(&cla.list, &t1.node);
    list_add_tail(&cla.list,&t2.node);
    list_add_tail(&cla.list,&t3.node);
    node_t* cur = cla.list.first;
    for(int i=0;i<cla.list.count;i++){
        student_t* st = (student_t*)cur;
        printf("age:%d\n",st->age);
        cur = cur->next;
    }

}