#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ind = 0;

typedef struct tree
{
    char data[15];
    int count;
    struct tree *left;
    struct tree *right;

}node;

struct lista{
    char name[15];
    char charac[4][15];
    }
    animal[15];
typedef struct lista list;

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
        //debug
        
        root -> count = ind;
        ind++;

        return root;
    } 
    else printf("raiz ja existe");
        return NULL;
}

// tirar o father char ->> tiramo                     //agora nao sabemos se da pra fazer isso aqui de declarar o array de struct nessa funçao, vamo ve
node *insert(node *root, char sonchar[][15], char name[]){

    if (root == NULL){
        //espaço eh alocado
        root = malloc(sizeof(node));
        //root -> data = name;
        strcpy(root->data, name);
        root -> left = NULL;
        root -> right = NULL;
        //debug
        

        root -> count = ind;
        ind++;
        return root;
    }
    else{
        //aqui vamos verificar a semelhança dele        /size v/
        //struct vai estar sendo chamado 
        //father char = node atual =>>>  animal[counter].charac[i]
        //index vai ser do node atual
        int index_ = root->count;
        char fatherchar[4][15];
        for(int i = 0; i < 4 ; i++){   //counter = animal anterior
            strcpy(fatherchar[i], animal[index_].charac[i]);
        }


        int resemblance = comparison(0, fatherchar , sonchar, 4);

        if(resemblance == 0){
            printf("animal %s nao valido\n", name);
            
        }
        else if(resemblance<=2){
             //debugzin
           
            root->left = insert(root->left, sonchar, name);
        }
        else if(resemblance>2){
                    //debug
            root->right = insert(root->right, sonchar, name);
        }

    }

}


int main()
{   
    node *root = NULL;
    //pode ser setada a quantidade de animais a serem adicionados, por hora vamos definir 4
    // as caracteristicas ja foram limitadas como 4
    //contador de pai


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
    printTree(root);
    //nome filho
    strcpy(animal[1].name,"abe");

    char caracteristics[][15] = {"caca", "as", "antenas", "te"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[1].charac[i], caracteristics[i]);
    }

    //definicao do pai para usar na insercao dos filhos 
    //char fatherchar[4][15];
    //for(int i = 0; i < 4 ; i++){   //counter = animal anterior
    //    strcpy(fatherchar[i], animal[counter].charac[i]);
    //}

    insert(root, animal[1].charac, animal[1].name );
    printf("\n");
    printTree(root);

}
