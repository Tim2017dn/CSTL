//
// Created by dolly on 2021/9/20.
//

#include "common.h"

void merge(int* arr, int* aux, int lo, int mid, int hi)
{

    int i = lo;
    int j = mid+1;

    for(int k = lo; k <= hi; k++){
        if(i>mid){
            aux[k] = arr[j];
            j++;
            continue;
        }

        if(j >hi){
            aux[k] = arr[i];
            i++;
            continue;
        }

        if(arr[i] <= arr[j]){
            aux[k] = arr[i];
            i++;
        }else{
            aux[k] = arr[j];
            j++;
        }
    }

    for(int k=lo; k<=hi; k++){
        arr[k] = aux[k];
    }
}

void mergeSort(int* arr,int* aux, int lo, int hi)
{
    if(lo>=hi) return;
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, aux, lo, mid);
    mergeSort(arr, aux, mid+1, hi);
    merge(arr, aux, lo, mid, hi);
}

int main()
{
    int arr[] = { 9, 8, 4, 7, 6, 5, 4, 3, 8, 2 ,1};
//    int arr[] = {4,2,1};
    int arrLen = 11;
    int* aux = malloc(sizeof(int)*arrLen);
    mergeSort(&arr, aux, 0 , arrLen-1);
    printArr(arr, arrLen);
}