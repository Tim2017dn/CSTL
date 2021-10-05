//
// Created by dolly on 2021/10/2.
//
#include "common.h"
struct Item{
    int num;
    char str[100];
};

int minus(struct Item x, struct Item y)
{
    return x.num - y.num ;
}

void swap(struct Item* x , struct Item* y){
    struct Item tmp;
    memcpy(&tmp, x, sizeof(struct Item));
    memcpy(x, y, sizeof(struct Item));
    memcpy(y, &tmp, sizeof(struct Item));
    return;
}

void quickSort(struct Item* list, int begin, int end, int pos){
    if(end < begin){
        return;
    }
    int lo = begin;
    int hi = end;
    while( lo < hi){
        while(minus(list[lo], list[pos]) <= 0){
            lo++;
        }
        while(minus(list[hi], list[pos]) > 0){
            hi--;
        }
        if(lo < hi){
            printf("swap list[%d] list[%d]\n", lo, hi);
            swap(&list[lo], &list[hi]);
            lo++;
            hi--;
        }

    }

    int find = hi;
    printf("swap list[%d] list[%d]\n", pos, find);
    swap(&list[pos], &list[find]);
    quickSort(list, begin, find - 1 , begin-1);
    quickSort(list, find+2, end, find+1 );
    return;
}

void printArr(struct Item* list, int listLen){
    for(int i=0; i<listLen; i++){
        printf("%d ",list[i].num);
    }
}

int main()
{
    int nums[] = {9, 8, 4, 7, 6, 5, 4, 6,3, 2 ,1};
    char* str[] = {"i","h","d","g","f","e","d","f","c","b","a"};
    struct Item item[11];
    int arrLen = 11;
//    int nums[] = { 9, 4,  7, 6, 4, 1};
//    char* str[] = {"a","d","g","f","d","a"};
//    int arrLen = 6;
//    struct Item item[arrLen];

    for(int i = 0; i < arrLen; i++){
        item[i].num = nums[i];
        strcpy(item[i].str, str[i]);
    }

//    for(int i = 0 ;i < arrLen; i++){
//        printf("%s ", item[i].str);
//    }
    quickSort(&item, 1, arrLen-1, 0);
    printArr(&item, arrLen);
}


