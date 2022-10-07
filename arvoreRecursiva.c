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


void deleteNode(node* head, int value){
    node *i = head;
    int x;
    while(i -> next!= NULL){
        if( i -> next ->value == value){
            node *aux = i ->next;
            i -> next = aux ->next;
            x=1;
            break;
        }
        else if( i -> value == value){
            node *aux = head;
            aux = head->next;
        }
        i = i -> next;
    }
    if(x!=1) printf("Numero nao encontrado\n");
        
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

int highest(node *head){
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

node *searchNode2(node *head, int value){
    node *aux = head;
    while (aux!= NULL){
        if (aux->value == value){
            
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
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
    node *novaLista;
    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("Essa e a lista encadeada em C, simbora.\nDigite o primeiro numero da lista:\n");
    int number;
    scanf("%d", &number);
    aux = createNode(number);
    head = insertAtBeginning(head, aux);

    int x=1;
    while(x==1){
        printf("\n------------------------------------------------------------------------------------------\n");
        printf("Escolha entre as opcoes:\n(1)inserir no comeco\n(2)inserir no final\n");
        printf("(3)Inserir apos um Node especifico\n(4)Informar o maior valor\n(5)Deletar um Node\n(6)Procurar um Node na lista\n(7)Concatenar duas listas\n(8)Imprimir Lista\n(0)Fechar o programa\n");
        printf("------------------------------------------------------------------------------------------\n");

        int choice, number, value;
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("Digite o Node a ser inserido:\n");
                int i;
                scanf("%d", &i);
                aux = createNode(i);
                head = insertAtBeginning(head, aux);
                print(head);
                break;
            case 2:
                printf("Digite o Node a ser inserido:\n");
                scanf("%d", &i);
                aux = createNode(i);
                insertAtEnd(head, aux);
                print(head);
                break;
            case 3:
                printf("Digite o Node anterior:\n");
                int aux1, aux2;

                scanf("%d", &aux1);

                node *aux_ = searchNode2(head, aux1);
                if (aux == NULL){
                    printf("numero nao encontrado\n");
                    break;
                }

                printf("Digite o Node a se inserido\n");

                scanf("%d", &aux2);
                aux = createNode(aux2);
                insertAfterAnother( aux_, aux);
                print(head);
                break;
            case 4:
                
                number = highest(head);
                printf("O maior numero e: %d\n", number);
                break;
            case 5:
                
                printf("Digite o numero a ser removido\n");
                scanf("%d", &value);
                deleteNode(head, value);
                break;
            case 6:
                printf("Digite o numero a ser encontrado\n");
                
                scanf("%d", &value);

                searchNode(head, value);
                break;
            case 7:
                printf("vamos criar uma nova lista de 5 componentes\n");
                
                for (int i=0; i < 5; i++){
                    int numb;
                    printf("numero %d:\n", i+1);
                    scanf("%d", &numb);
                    aux = createNode(numb);
                    novaLista = insertAtBeginning(novaLista, aux);
                
                }
                
                
                printf("Agora vamos juntar a lista anterior com essa nova\n");
                concatenate(head,novaLista);

                print(head);
                printf("\n");
                break;
            case 8:
                print(head);
                printf("\n");
                break;
            default: 
                x=0;
                break;
            

            
        }
        if (x==0){
            break;
        }

    }

    return 0;
}
