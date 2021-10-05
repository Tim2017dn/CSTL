//
// Created by dolly on 2021/9/20.
//

#include  "common.h"

void insertHelp(int* arr, int pos, int curValue){
    int begin = 0;
    int end = pos - 1;
    int mid = (begin + end) / 2;
    while(begin < end){
        if(arr[mid] == curValue){
            // find mid
            break;
        }else if(arr[mid] > curValue){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
        mid = (begin + end) / 2;
    }

    // mid 即插入的位置
    for(int i = pos; i > mid; i--){
        arr[i] = arr[i-1];
    }
    arr[mid] = curValue;

}

void insertSort(int* arr, int arrLen)
{
    if(arrLen == 0 || arrLen==1){
        return;
    }
    for(int i = 1; i < arrLen; i++){
        insertHelp(arr, i, arr[i]);
    }
}

int main()
{
    int arr[10] = { 9, 8, 4, 7, 6, 5, 4, 3, 2 ,1};
    int arrLen = 10;
    insertSort(&arr, arrLen);
    printArr(arr, arrLen);
}
