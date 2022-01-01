//
// Created by dolly on 2021/11/3.
//
#include "common.h"
int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}


typedef struct _item{
    int num;
    char name[100];
}item;

int cmp2(const void* a, const void* b){
    int v1 = ((item*)a)->num;
    int v2 = ((item*)b)->num;
    return (v1-v2);
}

int cmp3(const void* a, const void* b){
    char* v1 = ((item*)a)->name;
    char* v2 = ((item*)b)->name;
    return strcmp(v1, v2);
}

int main(){
//    int arr[5] = {6, 4, 8, 2, 10};
//
//    qsort(arr, 5, sizeof(int), cmp);
//
//    for(int i=0;i<5;i++){
//        printf("%d \t", arr[i]);
//    }
    item items[6];
    int nums[6] = {6,  4, 2, 8, 10,   2};
    char* names[6] = {"cc", "bb", "dd", "ee", "aa", "ab"};
    for(int i = 0; i < 6; i++){
        items[i].num = nums[i];
        strcpy(items[i].name, names[i]);
    }
    qsort(items, 6, sizeof(item), cmp2);

    for(int i=0;i<6;i++){
        printf("%s\t", items[i].name);
    }

}