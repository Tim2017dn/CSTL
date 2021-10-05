//
// Created by dolly on 2021/10/3.
//
#include "common.h"
//typedef struct{
//    int num;
//    char name[100];
//} Item;
//
//typedef struct _Node{
//    Item* item;
//    struct _Node* next;
//} Node;

static Node* head;
int n = 0;

void push(Item* it){
    Node* node = malloc(sizeof(Node));
    node->item = it;
    if(n==0){
        head = node;
        node->next = NULL;
    }else{
        node->next = head;
        head = node;
    }
    n++;
}

Node* top(){
    return head;
}

Node* pop(){
    if(top() == NULL){
        return NULL;
    }
    Node* cur = head;
    head = head->next;
    return cur;
}


int main(){
    int nums[] = {9, 8, 4, 7, 6, 5, 4, 6, 3, 2 ,1};
    char* str[] = {"i","h","d","g","f","e","d","f","c","b","a"};
    int arrLen = 11;

    for(int i = 0; i < arrLen; i++){
        //Node* node = malloc(sizeof(Node));
        Item* item = malloc(sizeof(Item));
        item->num = nums[i];
        strcpy(item->name,str[i]);
        push(item);
    }
    Node* no = head;

    while(top() != NULL){
        Node *cur = pop();
        printf("%d ", cur->item->num);
    }

}