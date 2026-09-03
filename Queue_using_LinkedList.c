//write a C program to implement a Queue using linked list. And the program should include functions to enqueue and dequeue elements from the queue. And also include a function to display the elements of the queue. And also include a main function to test the queue operations by providing a menu-driven interface to the user.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    if (*rear == NULL) {
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate an error
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(&rear, data);
                break;
            case 2:
                data = dequeue(&front);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}