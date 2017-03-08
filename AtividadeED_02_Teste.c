#include <stdio.h>
#include <stdlib.h>


typedef struct Lista{
    int valor;
    struct Lista* next;
}Lista;

extern void InsertNode(Lista** head, int valor, int indice);
extern void RemoveNode(Lista** head, int indice);
extern void CreateNode(Lista** node, int valor);
extern void PrintList(Lista* head);
/*extern void LiberaMemoria(Lista** head, int indice);*/


int main(int argc, const char * argv[]) {

    int valor, indice;
    char tmp, opcao;
    Lista* head = NULL;

    while (1) {
        scanf("%c", &opcao);
        if (opcao == 'q') {
            /*LiberaMemoria(&head, indice);*/
            break;
        }


        switch (opcao) {
            case 'f':
                // INSERIR NA FRENTE
                scanf("%d", &valor);
                scanf("%c", &tmp);

                InsertNode(&head, valor, 0);
                break;
            case 'i':
                // inserir no indice
                scanf("%d %d", &indice, &valor);
                scanf("%c", &tmp);
                InsertNode(&head, valor, indice);
                break;
            case 'r':
                // remover na frente
                scanf("%c", &tmp);
                RemoveNode(&head, 0);
                break;
            case 'd':
                // remover no indice
                scanf("%d", &indice);
                scanf("%c", &tmp);
                RemoveNode(&head, indice);
                break;
            default:
                break;
        }

        PrintList(head);

    }

    return 0;
}


void CreateNode(Lista** node, int valor){
    if (!(*node)) {
        (*node) = malloc(sizeof(Lista));
    }

    (*node)->valor = valor;
    (*node)->next = NULL;
}

void PrintList(Lista* head){
    if (!head) {
        printf("empty\n");
    }else{
        while (head->next) {
            printf("%d ", head->valor);
            head = head->next;
        }
        printf("%d\n", head->valor);
    }
}

void InsertNode(Lista** head, int valor, int indice){

    int i;

    if (!(*head)) {
        CreateNode(head, valor);
        return;
    }

    Lista* newNode = NULL, *temp = NULL, *p = NULL;
    CreateNode(&newNode, valor);

    if (indice == 0) {
        temp = *head;
        *head = newNode;
        newNode->next = temp;
    }else{
        p = (*head);
        for (i = 0; i < indice; i++) {
            if (!(p)->next || i == indice - 1){
                temp = (p)->next;
                (p)->next = newNode;
                newNode->next = temp;
                break;
            }
            p = p->next;
        }
    }
}

void RemoveNode(Lista** head, int indice){

    int i;

    if (!(*head)) {
        return;
    }

    Lista *temp = NULL, *p = NULL;

    if (indice == 0) {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }else{
        p = *head;
        for (i = 0; i < indice; i++) {
            if (i == indice - 1) {
                temp = p->next;
                p->next = temp->next;
                free(temp);
                return;
            }
            if (!p->next) {
                return;
            }
            p = p->next;
        }
    }

/*void LiberaMemoria(Lista** head, int indice){
    int i;

    Lista *temp = NULL, *p = NULL;

    p = *head;
    for (i = 0; i < indice; i++){
        temp = p->next;
        p->next = temp->next;
        free(p);
    }
  }*/
}
