#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createSLL();
void insertBegin(Node** head, int newelement);
void insertAfter(Node* head, int newelement, int existingelement);
int deleteBefore(Node** head, int existingelement);
int isempty(Node* head);
void display(Node* head);

Node* createSLL() {
    return NULL;
}

void insertBegin(Node** head, int newelement) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = newelement;
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(Node* head, int newelement, int existingelement) {
    Node* current = head;
    
    while (current != NULL && current->data != existingelement) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Element %d not found in the list.\n", existingelement);
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    newNode->data = newelement;
    newNode->next = current->next;
    current->next = newNode;
}

int deleteBefore(Node** head, int existingelement) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List is too short to delete an element before %d.\n", existingelement);
        return -1;
    }
    
    Node* temp = NULL;
    Node* prev = NULL;
    Node* current = *head;
    
    if (current->next->data == existingelement) {
        temp = *head;
        *head = (*head)->next;
        int deletedData = temp->data;
        free(temp);
        return deletedData;
    }
    
    while (current->next != NULL && current->next->data != existingelement) {
        prev = current;
        current = current->next;
    }
    
    if (current->next == NULL) {
        printf("Element %d not found in the list.\n", existingelement);
        return -1;
    }
    
    if (prev != NULL) {
        temp = prev->next;
        prev->next = current->next;
        int deletedData = temp->data;
        free(temp);
        return deletedData;
    }
    
}

int isempty(Node* head) {
    return head == NULL;
}

void display(Node* head) {
    Node* current = head;
    if (isempty(head)) {
        printf("The list is empty.\n");
        return;
    }
    
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createSLL();
    int choice, newelement, existingelement;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element at the beginning\n");
        printf("2. Insert element after a given element\n");
        printf("3. Delete element before a given element\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the new element: ");
                scanf("%d", &newelement);
                insertBegin(&head, newelement);
                break;
                
            case 2:
                printf("Enter the new element and the existing element after which to insert: ");
                scanf("%d %d", &newelement, &existingelement);
                insertAfter(head, newelement, existingelement);
                break;
                
            case 3:
                printf("Enter the existing element before which to delete: ");
                scanf("%d", &existingelement);
                int deletedData = deleteBefore(&head, existingelement);
                if (deletedData != -1) {
                    printf("Deleted element: %d\n", deletedData);
                }
                break;
                
            case 4:
                display(head);
                break;
                
            case 5:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
                break;
        }
    }
    
    return 0;
}
