#include<stdio.h>
#include<stdlib.h>

struct listaEncadeada{
    int value;
    //ponteiro que vai apontar para o proximo node da lista >>
    struct listaEncadeada* next;

};
typedef struct listaEncadeada node;

node *createNode(int value){
    //alocar um novo node usando malloc
    node *result = malloc(sizeof(node));
    //o valor do node criado sera o valor fornecido 
    result ->value = value;
    result ->next = NULL;

    return result;
}

void print(node *head){

    while ( head!= NULL){
        printf("%d--", head->value);
        head = head->next;
    }
    printf("\n");
}


void deleteNode(node* head, int value){
    node *i = head;
    while(i!= NULL){
        if( i -> next ->value == value){
            node *aux = i ->next;
            i -> next = aux ->next;
            break;

        }
        i = i -> next;
    }
        
    return;

}

void concatenate(node *firstList, node *secondList){
    node *i = firstList;

    while(i-> next != NULL){
        i = i -> next;
    }
    i -> next = secondList;
    secondList = NULL;
}

int *highest(node *head){
    node *i = head;
    int highest;
    highest = i -> value;
    while(i->next != NULL){
        if(i->value<i->next->value){
            highest = i->next->value;
        }
        i = i -> next;
    }
    return highest;
}


node *insertAtBeginning(node *head, node *insertedNode){
    insertedNode->next = head;
    head = insertedNode;
    
    return insertedNode;

}

void insertAtEnd(node *head, node*insertedNode){
    node *i = head;
    while(i->next!=NULL){ 
        i = i -> next;
    }

    i -> next = insertedNode;
    insertedNode -> next = NULL;


}

void insertAfterAnother(node *previousNode, node* insertedNode){
    insertedNode->next = previousNode -> next;
    previousNode->next = insertedNode;

}

node *searchNode(node *head, int value){
    node *aux = head;
    while (aux!= NULL){
        if (aux->value == value){
            printf("Achei!!!... o numero %d, ne?\n", aux->value);
            return aux;
        }
        aux = aux->next;
    }
    printf("numero nao encontrado\n");
    return NULL;
}

int main()
{
    node *head = NULL;
    node *aux;

    
    for (int i=0; i < 15 ; i++){
        aux = createNode(i);
        head = insertAtBeginning(head, aux);
    }
    print(head);
    
    node *temp = createNode(25);
    printf("\n");
    insertAtEnd(head, temp);

    print(head);
    printf("\n");
    deleteNode(head,25);
    print(head);

    node *primeiraLista = NULL;
    node *segundaLista = NULL;

    for (int i= 0; i<9; i++){
        aux = createNode(i);
        primeiraLista = insertAtBeginning(primeiraLista, aux);
    }
    printf("\n");
    print(primeiraLista);
    for (int i= 9; i<15; i++){
        aux = createNode(i);
        segundaLista = insertAtBeginning(segundaLista, aux);
    }
    printf("\n");
    print(segundaLista);
    printf("\n");

    concatenate(primeiraLista,segundaLista);
    print(primeiraLista);

    int x = highest(head);
    printf("\n maior = %d\n", x);


    return 0;
}
