//
// Created by dolly on 2021/10/3.
//

#include "common.h"

Node* root;
int n = 0;

int compare(Item* x, Item* y){
   return x->num - y->num;
}

Node* put2(Node* x, Node* cur){
    if( x == NULL){
        return cur;
    }
    int cmp = compare(cur->item, x->item);
    if(cmp < 0) x->left = put2(x->left, cur);
    else if (cmp >0 ) x->right = put2(x->right, cur);
    else  x->item = cur->item;
    // cal size
    return x;
}

void put(Item* item){

    Node *node = malloc(sizeof(Node));
    node->item = item;
    node->left =NULL;
    node->right = NULL;
    if(n == 0){
        root = malloc(sizeof(Node));
        root->left = NULL;
        root->right = NULL;
        root = node;

    }else {
        put2(root, node);
    }
    n++;
}



void printNode(Node* node){
    printf("node num:%d, str:%s\n",
            node->item->num, node->item->name);
}

void printTree(Node* node){
    if(node == NULL){
        return;
    }
    printNode(node);
    printTree(node->left);
    printTree(node->right);
}

void PrePrint(Node* node){
    if(node == NULL){
        return;
    }
    PrePrint(node->left);
    printNode(node);
    PrePrint(node->right);
}

void postPrint(Node* node){
    if(node == NULL){
        return;
    }

    postPrint(node->left);
    postPrint(node->right);
    printNode(node);
}

int main(){
    int nums[] = {4,2,7,1,3,5,8,6,9,4,9};
    char* str[] = {"i","h","d","g","f","e","d","f","c","b","a"};
    int arrLen = 11;

    for(int i=0; i <arrLen; i++){
        Item* item = malloc(sizeof(Item));
        item->num = nums[i];
        strcpy(item->name, str[i]);
        put(item);
    }

//    printTree(root);
//    PrePrint(root);
    postPrint(root);

}
