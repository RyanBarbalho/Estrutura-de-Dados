#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ind = 0;

typedef struct tree
{
    char data[15]; //nome do animal
    int count; //serve como index do node
    struct tree *left;
    struct tree *right;

}node;

struct lista{ //array de structs ->> informaçoes dos animais
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

// tirar o father char ->> tiramo                  
node *insert(node *root, char sonchar[][15], char name[]){

    if (root == NULL){
        //espaço eh alocado
        root = malloc(sizeof(node));
        //root -> data = name;
        strcpy(root->data, name);
        root -> left = NULL;
        root -> right = NULL;
        
        root -> count = ind;
        ind++;
        
    }
    else{//se nao for nulo, entao o node atual é o pai do node que sera inserido
        //father char = node atual =>>>  animal[counter].charac[i]
        //index vai ser do node atual
        int index_ = root->count; // index é a localizaçao do node
        char fatherchar[4][15];
        for(int i = 0; i < 4 ; i++){   
            strcpy(fatherchar[i], animal[index_].charac[i]);
        }


        int resemblance = comparison(0, fatherchar , sonchar, 4);

        if(resemblance == 0){
            printf("animal %s nao valido\n", name);
            
        }
        else if(resemblance<=2){
              
            root->left = insert(root->left, sonchar, name);
        }
        else if(resemblance>2){
                    
            root->right = insert(root->right, sonchar, name);
        }

    }

    return root;

}

int main()
{   
    //criando raiz null da arvore
    node *root = NULL;
    
    //adicionado o primeiro animal:
    strcpy(animal[0].name, "animal_1");

    //caracteristicas do animal_1
    char caracteristicas[][15] = {"a1", "a2", "b3", "a4"};
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[0].charac[i], caracteristicas[i]);
    }
    //animal raiz inserido 
    root = insertRoot(root, animal[0].name);
    //mostrando o animal raiz
    printTree(root);
    
    //nome do primeiro filho
    strcpy(animal[1].name,"animal_2");

    char caracteristics[][15] = {"a1", "b2", "b3", "b4"};
    //caracterisitcas filho sendo inseridas no struct de informaçoes do animal
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[1].charac[i], caracteristics[i]);
    }
    //animal 2
    root = insert(root, animal[1].charac, animal[1].name );
    printf("\n");
    printTree(root);
    strcpy(animal[2].name,"animal_3");
    //animal 3

    char caracteristicos[][15] = {"a1", "b2", "c3", "b4"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[2].charac[i], caracteristicos[i]);
    }
    root = insert(root, animal[2].charac, animal[2].name);
    
    strcpy(animal[3].name,"animal_4");
    //animal 4

    char caracteristicis[][15] = {"a1", "c2", "c3", "b4"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[3].charac[i], caracteristicis[i]);
    }
    root = insert(root, animal[3].charac, animal[3].name);
   
    strcpy(animal[4].name,"animal_5");
    //animal 5

    char caracteristices[][15] = {"a1", "a2", "b3", "b4"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[4].charac[i], caracteristices[i]);
    }
    root = insert(root, animal[4].charac, animal[4].name);

    strcpy(animal[6].name,"animal_6");
    //animal 6

    char caracteristiczs[][15] = {"a1", "c2", "c3", "c4"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[6].charac[i], caracteristices[i]);
    }
    root = insert(root, animal[6].charac, animal[6].name);


    printf("\n");
    printTree(root);
    printf("\n");

    printf("\n");
    search(root, "animal_4");
    
    search(root, "animal_8");
    
   

}
