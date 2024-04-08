#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

void insert(char x, Node *head) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    newNode->data = x;
    curr->next = newNode;
}

void printList(Node *head) {
    Node *current = head->next; 
    while (current != NULL) {
        printf("%c  ", current->data);
        current = current->next;
    }
}

void insertMiddle(char x, Node *head, int position) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;

    if (position == 0) {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }

    Node *current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("This position is invalid!\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void verifyFirstParenthesis(Node *head) {
    Node *current = head->next; 
    if (current->data == '(') {
        return;
    } else {
        insertMiddle('(', head, 1);
    }
}

void verifySecondParenthesis(Node *head){
    Node *current = head;

    for(int i = 0; i < 4 && current != NULL; i++){
        current = current->next;
    }
    
    if(current == NULL){
        insertMiddle(')', head, 4);
    } else if(current->data == ')'){
        return;
    } else{
        insertMiddle(')', head, 4);
    }
}

void verifyHyphen(Node *head){
    Node *current = head;

    for(int i = 0; i < 10 && current != NULL; i++){
        current = current->next;
    }

    if(current == NULL){
        insertMiddle('-', head, 10);
    } else if(current->data == '-'){
        return;
    } else{
        insertMiddle('-', head, 10);
    }
}

int main() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL; 

    int option;
    char simpleInsert;
    int positionToInsert;
    char preciseInsert;
    
    printf("Type a number with 11 digits or with the format: (11) 11111-1111, if its not in the format it will be adjusted! \n\n");

    do {
        printf("\nType a number, 1 - Insert, 2 - InsertInAPosition, 3 - PrintTheLinkedList, 4 - VerifyThePhoneNumber, 0 - Exit: ");
        scanf("%d", &option);

        switch (option) {
            case 0:
                printf("The program is finishing.\n");
                break;
            case 1:
                printf("Insert the character: \n");
                scanf(" %c", &simpleInsert); 
                insert(simpleInsert, head);
                break;
            case 2:
                printf("Insert the position in the list you want to allocate: \n");
                scanf("%d", &positionToInsert);
                printf("Insert the character: \n");
                scanf(" %c", &preciseInsert); 
                insertMiddle(preciseInsert, head, positionToInsert);
                break;
            case 3:
                printf("The list: \n");
                printList(head);
                break;
            case 4:
                printf("The telephone will be verified if it is in the format (PT-BR), if it's not will be adjusted! \n");
                verifyFirstParenthesis(head);
                verifySecondParenthesis(head);
                verifyHyphen(head);
                break;
            default:
                printf("Invalid number. Try again.\n");
        }

    } while (option != 0);

    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
