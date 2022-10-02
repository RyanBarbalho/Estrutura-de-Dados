#include<stdio.h>
#include<stdlib.h>

typedef struct nodeArv{
    int data;
    struct nodeArv *left;
    struct nodeArv *right;

}nodeArv;

//node = raiz
nodeArv *create()
{
    return NULL;
}

nodeArv *delete(nodeArv *node, int number)
{
    nodeArv *aux1, *aux2;

    if(node == NULL)
    {
        return node;
    }

    if (number < node->data){
        delete(node->left, number);
    }
    else if(number > node->data){
        delete(node->right, number);
    }
    else{       //entra na condicao do numbero ser igual ao no
        
        if(node->left == NULL && node->right == NULL){
            free(node);
            node = NULL;
        }
        else if(node->right == NULL){
            aux1 = node;
            node = node->left;
            free(aux1);
        }
        else if(node->left==NULL){
            aux1 = node;
            node = node->right;
            free(aux1);
        } // tem dois filhos >>
        else{
            aux2 = node->left;
            while (node->right != NULL){
                node = node->right;
            }
            node->data = aux2->data;

            aux2->data = number;
            node->left = delete(node->left, number);

        }


    }


    return node;
}

nodeArv *searchTree(nodeArv *node, int number)
{
    if(node == NULL){
        printf("Numero nao encontrado!\n");
        return node;
    }
    else{
        if(node -> data == number){
            printf("Numero %d encontrado\n", node->data);
        }
        else if(number > node->data){
            searchTree(node -> right, number );
        }
        else if(number< node->data){
            searchTree(node -> left, number);
        }
    }
    
    return node;

}

void printTree(nodeArv *node)
{
    if(node != NULL){
        printf("(");
        printTree(node->left);
        printf("(%d)", node->data);
        printTree(node->right);
        printf(")");
    }
    else printf("( )");
}


nodeArv *insert(nodeArv *node, int value)
{
    //se estiver vazia vai inserir
    if(node == NULL)
    {
        node = (nodeArv*)malloc(sizeof(nodeArv));
        node->data = value; 
        node->left = NULL;
        node->right = NULL;   
    }
    else{
        //se o valor for menor que a raiz vai pra esquerda
        if(node->data > value){
            //o valor do no a esquerda recebe a funçao de inserir
            node->left = insert(node->left, value);
        }
        else if(node->data < value){
            //o valor do no a direita recebe a funçao de inserir
            node->right = insert (node->right, value);
        }


    }
    return node;

}

int main()
{
    nodeArv *root;
    int element1=8,element2=6,element3=4,element4=10,element5=11,element6=24,element7=3;

    root = create();

    root = insert(root, element1);
    root = insert(root, element2);
    root = insert(root, element3);
    root = insert(root, element4);
    root = insert(root, element5);
    root = insert(root, element6);
    root = insert(root, element7);

    printTree(root);

    int number = 5;
    printf("\n");
    root = searchTree(root, number);
    printf("\n");

    int number2 = 24;
    root = searchTree(root, number2);
    printf("\n");

    root = delete(root, 10);

    printTree(root);

}