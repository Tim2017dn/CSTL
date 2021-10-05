//
// Created by dolly on 2021/10/4.
//
#include "common.h"


static Node* root;
static bool init = false;
static Node* newNode(Item* item){
    Node* node = malloc(sizeof(Node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    node->size = 1;
    return node;
}

int compare(Node* x, Node* y){
    return x->item->num - y->item->num;
}

int size(Node* x){
    if(x ==NULL){
        return 0;
    }
    return x->size;
}


Node* rotateLeft(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
    return y;
}

Node* rotateRight(Node* x){
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
    return y;
}

Node* justify(Node* x){
    if(x->left == NULL && x->right == NULL){
        return x;
    }

    if(x->left == NULL && x->right->size == 2){
        if(x->right->left == NULL && x->right->right->size == 1 ){
            x = rotateLeft(x);
        }else if(x->right->right == NULL && x->right->left->size == 1){
            x->right = rotateRight(x->right);
            x = rotateLeft(x);
        }
    }else if( x->right == NULL && x->left->size == 2){
        if(x->left->right == NULL && x->left->left->size ==1){
            x = rotateRight(x);
        }else if(x->left->left =NULL && x->left->right->size == 1){
            x->left = rotateLeft(x->left);
            x = rotateRight(x);
        }
    }
    return x;

}


Node* put2(Node* x, Node* cur){
    if( x == NULL){
        return cur;
    }

    int cmp = compare( cur, x);
    if(cmp < 0) x->left = put2(x->left, cur);
    else if(cmp > 0) x->right = put2(x->right, cur);
    else x->item = cur->item;
//    bool need = false;
//    if(x== root){
//        need = true;
//    }
    x = justify(x);
//    if(need){
//        root = x;
//    }
    x->size = size(x->left) + size(x->right) + 1;
    return x;
}

void put(Item* item){

    Node *node = newNode(item);
    if(init == false){
        root = node;
        init = true;
    }else{
        root = put2(root, node);
    }
}

void printNode(Node* x){
    printf("node,num:[%d], size:[%d]\n",x->item->num,x->size);
}

typedef struct __Node{
    Node* node;
    struct __Node* next;
} NodeQ;

NodeQ* head, *tail;
int sizeQ = 0;

void enqueue(NodeQ* node){
    if(sizeQ == 0){
        head = tail = node;
    }else{
        tail->next = node;
        tail = node;
    }
    sizeQ++;
}

NodeQ* dequeue(){
    NodeQ* cur = head;
    head = head->next;
    sizeQ--;
    return cur;
}

int lenOfQueue(){
    return sizeQ;
}


NodeQ* Node2NodeQ(Node* x){
    NodeQ* res = malloc(sizeof(NodeQ));
    res->node = x;
    res->next = NULL;
    return res;
}

void printTree(Node* x){
    enqueue(Node2NodeQ(x));
    while(lenOfQueue() != 0){
        NodeQ* tmp = dequeue();
        Node* cur = tmp->node;
        if(cur->left != NULL){
            enqueue(Node2NodeQ(cur->left));
        }
        if(cur->right != NULL){
            enqueue(Node2NodeQ(cur->right));
        }
        printNode(cur);
    }
}



int main(){
//    int nums[] = {4,2,7,1,3,5,8,6,9,4,9};
//    char* str[] = {"i","h","d","g","f","e","d","f","c","b","a"};
//    int arrLen = 11;
    int nums[] = {4,2,1, 8, 6};
    char* str[] = {"i","h","d","g","f","e","d","f","c","b","a"};
    int arrLen = 5;

    for(int i=0; i <arrLen; i++){
        Item* item = malloc(sizeof(Item));
        item->num = nums[i];
        strcpy(item->name, str[i]);
        put(item);
    }
    printTree(root);
}