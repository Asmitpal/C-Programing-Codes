#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;

//Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d enqueued to queue\n", value);
}

//Dequeue operation
int dequeue() {
    if (front == -1 ){
        printf("Queue is empty\n");
        return -1;
    }
    else {
        int value = queue[front];
        front++;
        if (front > rear) {
            front = 0;
            rear = -1;
        }
        return value;
    }
}

//Display operation
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

//Main function
int main() {
    int choice, value;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("%d dequeued from queue\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}