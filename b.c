#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>

struct node{
    int element;
    struct node *left;
    struct node *right;
};

//funcao para criar novo nó
struct node* newNode(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->element = item;

    temp->left = NULL;
    temp->right = NULL;
    return temp;

}

void inOrder(struct node* raiz){

    if(raiz!=NULL){
        inOrder(raiz->left);
        printf("%d\n", raiz->element);
        inOrder(raiz->right);

    }

}
//isert no

struct node* insert(struct node* node, int element){
    //se a arvore estiver vazia insere o numero 
    if(node == NULL){
        return newNode(element);
    }
    if(element> node->element){
        node->left = insert(node->left, element);

    }
    else if(element< node->element){
        node->right = insert(node->right, element);

    }

    return node;

}

int main()
{
    struct node* raiz = NULL;
    printf("\nvamos inserir a raiz\n");

    int r1;
    scanf("%d", &r1);
    insert(raiz, r1);

    int p= 1;
    while (p==1){
        printf("\nescreva o numero a ser inserido\n");

        int n;

        scanf("%d", &n);
        insert(raiz, n);

        printf("continua? (s/n)\n");

        char resp;

        scanf("%s", &resp);
        tolower(resp);

        if (resp=='s'){
            continue;
        }
        else{
            p=0;
            break;
        }
    }
    //print inorder transversal da arvore binaria
    inOrder(raiz);

    return 0;
}