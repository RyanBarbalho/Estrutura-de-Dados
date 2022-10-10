#include<stdio.h>
#include<stdlib.h>

typedef struct nAryTree{
    int data;
    struct treeNode *children;
    struct treeNode *next; // sibling

}node;


node *createNode(int value){
    node *number = malloc(sizeof(node));

    number -> data = value;
    number -> children = NULL;
    number -> next = NULL;
}

node *insertRoot(node *root, node* newNode)
{
    if(root == NULL){
        root = newNode;

    }
    else if(root !=)
}

int main()
{

    return 0;
}
