//
// Created by dolly on 2021/9/20.
//
#include "common.h"

void quickHelp(int* arr, int begin, int end, int pos)
{
    if(begin > end){
        return;
    }
    int i = begin;
    int j = end;
    int tar = arr[pos];
    while( i <= j ){
        while( arr[i] <=  tar ){
            i++;
        }
        while( arr[j] > tar){
            j--;
        }
        if(i <= j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            printf("swap arr[%d] arr[%d]\n", i, j);
        }
    }
    printf("swap arr[%d] arr[%d]\n", pos, j);
    arr[pos] = arr[j];
    arr[j] = tar;
    quickHelp(arr, begin, j-1,0);
    quickHelp(arr, j+2, end, j+1);
}

void quickSort(int* arr, int arrLen)
{
    quickHelp(arr, 1, arrLen-1, 0);
}


int main()
{
//    int arr[] = { 9, 8, 4, 7, 6, 5, 4, 3, 2 ,1};
    int arr[] = {9, 8, 4, 7, 6, 5, 4, 6, 3, 2, 1};
    quickSort(&arr, 11);
    for(int i=0;i<11;i++){
        printf("%d ", arr[i]);
    }

}