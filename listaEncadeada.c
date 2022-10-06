#include<stdio.h>
#include<stdlib.h>

struct listaEncadeada{
    int value;
    //ponteiro que vai apontar para o proximo node da lista >>
    struct listaEncadeada* next;

};
typedef struct listaEncadeada node;

void print(node *head){

    while ( head!= NULL){
        printf("%d--", head->value);
        head = head->next;
    }
    printf("\n");
}


node *createNode(int value){
    //alocar um novo node usando malloc
    node *result = malloc(sizeof(node));
    //o valor do node criado sera o valor fornecido 
    result ->value = value;
    result ->next = NULL;

    return result;
}

node *insertAtBeginning(node *head, node *insertedNode){
    insertedNode->next = head;
    head = insertedNode;
    
    return insertedNode;

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
    aux = searchNode(head, 2);
    printf("\n");
    aux = searchNode(head, 25);
    
    aux = searchNode(head, 8);
    //criar novo node 25 e depois inserir ele
    node *temp = createNode(25);
    insertAfterAnother(aux, temp);
    
    print(head);

    return 0;
}