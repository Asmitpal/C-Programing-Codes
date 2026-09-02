#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *create_node(int value)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_beginning(int value)
{
    struct node *new_node = create_node(value);
    if (new_node == NULL) return;
    new_node->next = head;
    if (head == NULL) tail = new_node;
    else head->prev = new_node;
    head = new_node;
}

void insert_end(int value)
{
    struct node *new_node = create_node(value);
    if (new_node == NULL) return;
    new_node->prev = tail;
    if (tail == NULL) head = new_node;
    else tail->next = new_node;
    tail = new_node;
}

int insert_position(int value, int position)
{
    struct node *current;
    struct node *new_node;
    int index;

    if (position < 1) return 0;
    if (position == 1) {
        insert_beginning(value);
        return 1;
    }
    current = head;
    for (index = 1; index < position - 1 && current != NULL; index++)
        current = current->next;
    if (current == NULL) return 0;
    if (current->next == NULL) {
        insert_end(value);
        return 1;
    }
    new_node = create_node(value);
    if (new_node == NULL) return 0;
    new_node->prev = current;
    new_node->next = current->next;
    current->next->prev = new_node;
    current->next = new_node;
    return 1;
}

int delete_beginning(void)
{
    struct node *removed_node;
    if (head == NULL) return 0;
    removed_node = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    else head->prev = NULL;
    free(removed_node);
    return 1;
}

int delete_end(void)
{
    struct node *removed_node;
    if (tail == NULL) return 0;
    removed_node = tail;
    tail = tail->prev;
    if (tail == NULL) head = NULL;
    else tail->next = NULL;
    free(removed_node);
    return 1;
}

int delete_position(int position)
{
    struct node *current;
    int index;
    if (position < 1 || head == NULL) return 0;
    if (position == 1) return delete_beginning();
    current = head;
    for (index = 1; index < position && current != NULL; index++)
        current = current->next;
    if (current == NULL) return 0;
    if (current == tail) return delete_end();
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return 1;
}

void display(void)
{
    struct node *current;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Forward:  ");
    for (current = head; current != NULL; current = current->next) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" <-> ");
    }
    printf("\nBackward: ");
    for (current = tail; current != NULL; current = current->prev) {
        printf("%d", current->data);
        if (current->prev != NULL) printf(" <-> ");
    }
    printf("\n");
}

void free_list(void)
{
    while (head != NULL) delete_beginning();
}

int main(void)
{
    int choice, value, position;

    while (1) {
        printf("\n-- Doubly Linked List Menu --\n");
        printf("1. Insert at beginning\n2. Insert at position\n3. Insert at end\n");
        printf("4. Delete from beginning\n5. Delete from position\n6. Delete from end\n");
        printf("7. Display list\n8. Exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            free_list();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_beginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                if (!insert_position(value, position)) printf("Position out of bounds.\n");
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(value);
                break;
            case 4:
                if (!delete_beginning()) printf("List is empty.\n");
                break;
            case 5:
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                if (!delete_position(position)) printf("Position out of bounds.\n");
                break;
            case 6:
                if (!delete_end()) printf("List is empty.\n");
                break;
            case 7:
                display();
                break;
            case 8:
                free_list();
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
