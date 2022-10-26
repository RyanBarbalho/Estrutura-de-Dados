#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree
{
    char data[15];
    struct tree *left;
    struct tree *right;

}node;

void printTree(node *root)
{
    if(root != NULL){
        printf("(");
        printTree(root->left);
        printf("(%s)", root->data);
        printTree(root->right);
        printf(")");
    }
    else printf("( )");
}

//comparacao se as caracteristicas sao iguais
int comparison(int resembles , char fatherList[][15], char sonList[][15], int size){

    for(int i = 0; i < size ; i++){

        if (strcmp(fatherList[i], sonList[i]) == 0){
            resembles++;
        }
    }
    return resembles;

}

node *insertRoot(node *root, char name[]){
    if (root == NULL){
        root = malloc(sizeof(node));

        strcpy(root->data, name);
        root -> left = NULL;
        root -> right = NULL;
        printf("%s", root->data);

        return root;
    } 
    else printf("raiz ja existe");
        return NULL;
}


node *insert(node *root, char fatherchar[][15], char sonchar[][15], char name[]){

    if (root == NULL){
        //espaço eh alocado
        root = malloc(sizeof(node));
        //root -> data = name;
        strcpy(root->data, name);
        root -> left = NULL;
        root -> right = NULL;
        printf("%s\n", root->data);
    }
    else{
        //aqui vamos verificar a semelhança dele        /size v/
        int resemblance = comparison(0, fatherchar , sonchar, 4);

        if(resemblance == 0){
            printf("animal %d nao valido\n", name);
            
        }
        else if(resemblance<=2){
            printf("animal vai a esquerda\n"); //debugzin
            root = insert(root->left, fatherchar, sonchar, name);
        }
        else if(resemblance>2){
            printf("animal vai a esquerda\n");
            root = insert(root->right, fatherchar, sonchar, name);
        }

    }

}


int main()
{   
    node *root = NULL;
    //pode ser setada a quantidade de animais a serem adicionados, por hora vamos definir 4
    // as caracteristicas ja foram limitadas como 4
    int number = 4;
    int counter = 0;

    struct lista{
    char name[15];
    char charac[4][15];
    }
    animal[number];

    //primeiro animal
    strcpy(animal[0].name, "maceico");

    //caracteristicas do maceico
    char caracteristicas[][15] = {"pelo", "cauda", "antenas", "asas"};
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[0].charac[i], caracteristicas[i]);
    }
    //animal raiz inserido 
    root = insertRoot(root, animal[0].name);
    //adicionar os proximos animais

    //nome filho
    strcpy(animal[1].name,"abe");
    char caracteristics[][15] = {"caca", "as", "antenas", "te"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[1].charac[i], caracteristicas[i]);
    }
    //definicao do pai para usar na insercao dos filhos 
    char fatherchar[4][15];
    for(int i = 0; i < 4 ; i++){
        strcpy(fatherchar[i], animal[counter].charac[i]);
    }
    root = insert(root, fatherchar, animal[1].charac, animal[1].name);

    printTree(root);




    
    
   
 
    
    //char animaList[4][15];
    //char name[15]= "maceico";
    //int father = 0;

    //animal 1 adicionado, agora vamos inserir na arvore


    

}