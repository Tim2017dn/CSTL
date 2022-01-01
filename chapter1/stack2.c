//
// Created by dolly on 2021/11/3.
//
#include "common.h"
#define INT_MAX 127
Item arr[INT_MAX];
Item* arr2[INT_MAX];
int size;


Item newItem(){
    Item i1;
    strcpy(i1.name, "dong");
    i1.num = 10;
    return i1;
}

Item* newItem2(int num, char* name){
    Item* item = malloc(sizeof(Item));
    item->num = num;
    strcpy(item->name, name);
    return item;
}


void push(Item item){
    if(size < INT_MAX){
        arr[size++] = item;
    }
}

void push2(Item* item){
    if(size < INT_MAX){
        arr2[size++] = item;
    }
}

//Item pop(){
//    if(size == 0){
//        return NULL;
//    }
//    Item top =  arr[size-1];
//
//}

Item* pop(){
    if(size ==0 ){
        return NULL;
    }

    Item* it = arr2[size-1];
    size--;
    return it;
}

int main(){
//    Item item1 = newItem();
//    strcpy(item1.name,"ning");
//    printf("name:%s\n", item1.name);
//
//    Item item2 = newItem();
//    strcpy(item2.name,"nin2");
//    printf("name:%s\n", item2.name);
//    printf("name:%s\n", item1.name);
    int nums[5] = {4, 2, 6, 0, 8 };
    char* name[5] = {
            "str4", "str2", "str6", "str0", "str8"
    };

    for(int i=0; i< 5; i++){
        Item *item = newItem2(nums[i], name[i]);
        push2(item);
    }

    Item *ptr = pop();
    printf("num:%d,name:%s\n", ptr->num, ptr->name);
    Item *item = newItem2(10, "str10");
    push2(item);


    for(int i=0;i<5;i++){
        Item *ptr = pop();
        printf("num:%d,name:%s\n", ptr->num, ptr->name);
    }

}