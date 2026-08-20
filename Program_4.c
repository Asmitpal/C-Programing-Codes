//write a code in c where the program takes an integer input from the user and store in the bigining of the linked list, end and any position and then display the linked list using functions.

#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
// Displaying the list
void display() {
    struct node *temp=head;
    if(temp==NULL) {
        printf("Empty list\n");
        return;
    }
    printf("Linked List\n");
    while(temp!=NULL) {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n\n");
}
//Inserting at the begining
void insert_begining(int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the begining\n", val);
}
//Inserting at the end
void insert_end(int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL) {
        head=newNode;
        printf("Inserted %d at the first position\n", val);
        return;
    }
    struct node *temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    printf("Inserted %d at the end\n", val);
}
//Inserting at any position
void insert_pos(int val, int pos)
{
    if (pos < 1)
    {
        insert_begining(val);
        return;
    }
    struct node *temp=head;
    for(int i=1; i<pos-1 && temp!=NULL; i++) 
    {
        temp=temp->next;
    }
    if(temp==NULL) {
        printf("Position out of bounds. \n");
        return;
    }
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=temp->next;
    temp->next=newNode;
    printf("Inserted %d at position %d\n", val, pos); 
}
void free_memo()
{
    struct node *temp=head;
    while(temp!=NULL) {
        struct node *nextNode=temp->next;
        free(temp);
        temp=nextNode;
    }
}

int main() {
    int choice, val;
    while(1) {
        printf("-- Linked List Insertion Menu --\n");
        printf("1. Insert at begining\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert at begining: ");
                scanf("%d", &val);
                insert_begining(val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 3:
                int pos;
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position to insert (1-based index): ");
                scanf("%d", &pos);
                insert_pos(val, pos);
                break;
            case 4:
                display();
                break;
            case 5:
                free_memo();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                return 0;
        }
    }
}