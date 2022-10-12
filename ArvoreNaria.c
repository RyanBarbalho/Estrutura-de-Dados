#include<stdio.h>
#include<stdlib.h>

typedef struct nAryTree{
    int data;
    struct treeNode *children;
    struct treeNode *next; // sibling

}node;


node *createNode(int value){
    node *number = malloc(sizeof(node));

    if (number != NULL){
        number -> data = value;
        number -> children = NULL;
        number -> next = NULL;

    }
   
    return number;
}

node *insertChildren(node *root, int value)
{
    node *newNode = createNode(value);

    if (root == NULL){
        root = newNode;
    }
    else
    {
        node *aux = root;

        while (aux->next != NULL){
            aux = aux->next;
        }

        aux->next = newNode;
    }
    
    return root;
}


node *delete(node *root, int parentNumber, int childNumber){
    node *aux = root;

    if(aux == NULL){
        return NULL;
    }
    if(root -> data == parentNumber) //achou
    {
        
        if(aux -> children != NULL){
            aux = root ->children;         
            root = aux;
            aux -> next = aux -> children;   
            
            return root;
                        
        }
        else if(aux->children == NULL){
            
            free(root);
            root = NULL;


        }
        return root;
     }

     node *auxSearch;

     auxSearch = delete(aux-> next, parentNumber, childNumber);
     if(auxSearch != NULL)
     {
        return auxSearch;
     }

    auxSearch = delete(aux -> children, parentNumber, childNumber);
     if (auxSearch != NULL)
     {
         return auxSearch;
     }
     return NULL;

}



node *insertNode(node *root, int parentNumber, int childNumber){

    if(root == NULL){
        return NULL;
    }
    //encontrou o node
    if(root -> data == parentNumber)
    {
        root -> children = insertChildren(root -> children, childNumber);

        return root;
    }

    node *auxSearch;
    
    //procura se e irmao
    auxSearch = insertNode(root-> next, parentNumber, childNumber);
    if(auxSearch != NULL)
    {
        return auxSearch;
    }
    //procura se e filho
    auxSearch = insertNode(root -> children, parentNumber, childNumber);
    if (auxSearch != NULL)
    {
        return auxSearch;
    }


    return NULL;

}

void pressTab(int level){
    for (int i = 0; i < level; i++)
    {
        printf("\t");
    }
}

void printloop(node *root, int level)
{

    while(root != NULL){

        //tab do level
        pressTab(level);

        printf("Node: %d\n", root -> data);

        if(root -> children != NULL)
        {
            //tab do level 
            pressTab(level);
        
            printf( "Children :\n" );

            printloop(root ->children, level+1);
        }

        root = root -> next; 
    }
    
}

void print(node *root)
{
    printloop(root, 0);
}

int main()
{
    int choice;
    //começamos criando uma raiz
    node *root = createNode(5);

    insertNode(root, 5, 3);
    insertNode(root, 5 , 7);
    insertNode(root, 7, 6);
    insertNode(root, 7, 10);
    insertNode(root, 3, 13);
    insertNode(root, 3, 18);
    insertNode(root, 6, 25);


    print(root);
    delete(root,3,18);
    print(root);



    return 0;
}

