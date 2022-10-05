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
        return NULL;
    }

    if (number < node->data){
        node->left = delete(node->left, number);
    }
    else if(number > node->data){
        node->right = delete(node->right, number);
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

int searchTree(nodeArv *node, int number)
{
    if(node == NULL){
        
        return 0;
    }
    else{
        if(node -> data == number){
            return 1;
        }
        else if(number > node->data){
            searchTree(node -> right, number );
        }
        else if(number< node->data){
            searchTree(node -> left, number);
        }
    }

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
    int var=1;
    printf("----------------------------------------------------------------------------------\nExemplo de Arvore Binaria em C, vamos la!\n----------------------------------------------------------------------------------\n\n\n");
    
    root = create();
    printf("Vamos comecar inserindo a raiz\nDigite a raiz:");
    int number;
    scanf("%d", &number);
    root = insert(root, number);
    while (var){
        printf("\n---------------------------------------------------------------------\nEscolha entre as opcoes abaixo:\nInserir Elemento(1)\nImprimir a Arvore(2)\nProcurar um elemento(3)\nApagar um elemento(4)\nEncerrar o programa(0)\n");
        printf("---------------------------------------------------------------------\n");
        int i;
        scanf("%d", &i);

        switch(i){
            case 1:
                printf("Digite o numero a ser inserido:");
                int num;
                scanf("%d", &num);
                root = insert(root, num); 
                break;
            case 2:
                printf("\n");
                printTree(root);
                printf("\n");
                break;
            case 3:
                printf("Digite o Elemento a ser encontrado\n");
                int search;
                scanf("%d", &num);

                search = searchTree(root, num);

                if(search==1) printf("Numero %d encontrado\n",num);
                else printf("Numero nao encontrado\n");
                break;
            case 4:
                printf("Digite o Elemento a ser apagado\n");

                scanf("%d", &num);
                root = delete(root, num);

                printf("Elemento deletado, nova arvore:\n");
                printTree(root);
                break;
            default:
                printf("Encerrando.....\n");
                var=0;
                break;

                
        }   


    }



}