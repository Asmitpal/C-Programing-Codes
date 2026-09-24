//Circular Linked list er traversal, insertion and deletion by user
#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Traversing and displaying the Circular Linked List
void display() {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("\nCircular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head: %d)\n", head->data);
}

// Inserting a node at a given position (1-based index)
void insertAtPosition(int val, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    // Case 1: Inserting in an empty list
    if (head == NULL) {
        if (pos != 1) {
            printf("\nList is empty. Inserting at Position 1 by default.\n");
        }
        head = newNode;
        newNode->next = head;
        printf("Node inserted successfully!\n");
        return;
    }

    // Case 2: Inserting at position 1 (Beginning)
    if (pos == 1) {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode; // Update Head
        printf("Node inserted at Position 1!\n");
        return;
    }

    // Case 3: Inserting at middle or end
    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("\nInvalid position! Position out of bounds.\n");
            free(newNode);
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at Position %d!\n", pos);
}

// Deleting a node from a given position (1-based index)
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("\nList is empty! Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;

    // Case 1: Only one node in the list
    if (head->next == head) {
        if (pos == 1) {
            free(head);
            head = NULL;
            printf("Node deleted. The list is now empty.\n");
        } else {
            printf("\nInvalid position!\n");
        }
        return;
    }

    // Case 2: Deleting the first node (Head)
    if (pos == 1) {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
        printf("Node deleted from Position 1!\n");
        return;
    }

    // Case 3: Deleting middle or last node
    struct Node* prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("\nInvalid position! Position out of bounds.\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from Position %d!\n", pos);
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- CIRCULAR LINKED LIST MENU ---");
        printf("\n1. Display / Traverse");
        printf("\n2. Insert Node");
        printf("\n3. Delete Node");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (1 for beginning): ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}