//
// Created by dolly on 2021/10/3.
//
#include "common.h"
int n = 0;

bool less(int*pq, int x, int y){
    return pq[x] - pq[y] < 0 ? true: false;
}

void swap(int*pq, int x, int y){
    int tmp = pq[x];
    pq[x] = pq[y];
    pq[y] = tmp;
}

void swim(int* pq, int k){
    while(k > 1 && less(pq, k, k/2)){
        swap(pq, k, k/2);
        k = k/2;
    }
}

void sink(int*pq, int k){
    while(2*k<= n){
        int j = 2*k;
        if(j < n && less(pq,j+1,j)){
            j++;
        }
        if(less(pq, j, k)){
            swap(pq, k, j);
            k = j;
        }else{
            break;
        }
    }
}

void insert(int* pq, int item){
    pq[++n] = item;
    swim(pq, n);
}

int delMin(int* pq){
    int res = pq[1];
    pq[1] = pq[n--];
    sink(pq, 1);
    return res;
}

int main(){
    int arrLen = 11;
    int arr[] = {9, 8, 4, 7, 6, 5, 4, 6, 3, 2, 1};
    int pq[arrLen + 1];
    for(int i=0; i<arrLen; i++){
        insert(pq, arr[i]);
    }

    for(int i=0;i<11;i++){
        int min = delMin(pq);
        printf("%d ",min);
    }

    return 0;
}