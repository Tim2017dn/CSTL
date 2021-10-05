//
// Created by dolly on 2021/10/3.
//
#include "common.h"

static Node *head, *tail;
static int size = 0;

int lenofQueue(){
    return size;
}

void enqueue(Item* item){
    Node* node = malloc(sizeof(Node));
    node->item = item;
    node->next = NULL;
    if(size ==0 ){
        head = node;
        tail = node;
    }else{
        tail->next = node;
        tail = node;
    }
    size++;
}

void enqueue2(Node* node){
    if(size ==0 ){
        head = node;
        tail = node;
    }else{
        tail->next = node;
        tail = node;
    }
    size++;
}

Item* dequeue(){
    if(size <= 0){
        return NULL;
    }
    Node* cur = head;
    head = head->next;
    size--;
    return cur->item;
}

Node* dequeue2(){
    if(size <= 0){
        return NULL;
    }
    Node* cur = head;
    head = head->next;
    size--;
    return cur;
}


//int main(){
//    int nums[] = {9, 8, 4, 7, 6, 5, 4, 6, 3, 2 ,1};
//    char* str[] = {"i","h","d","g","f","e","d","f","c","b","a"};
//    int arrLen = 11;
//
//    for(int i = 0; i < arrLen; i++){
//        //Node* node = malloc(sizeof(Node));
//        Item* item = malloc(sizeof(Item));
//        item->num = nums[i];
//        strcpy(item->name,str[i]);
//        enqueue(item);
//    }
//    Node* no = head;
//
//    while(size!= 0){
//        Item *cur = dequeue();
//        printf("%d ", cur->num);
//    }
//}
