// write a c program where we input a an element in any position in the linked list and also delete an element from any position

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
void insert_begining(int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the begining\n", val);
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

void delete_begining()
{
    if (head==NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    struct node *temp=head;
    head = head->next;
    printf("Deleting from the Begining.\n");
    free(temp);
}
void delete_pos (int pos)
{
    if(head==NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    if (pos<1)
    {
        printf("Invalid Position.\n");
        return;
    }
    if (pos==1)
    {
        delete_begining();
        return;
    }
    struct node *temp = head;
    for (int i=1; i<pos-1 && temp!=NULL; i++)
    {
        temp = temp -> next;
    }
    if (temp==NULL || temp->next==NULL)
    {
        printf("Position out of bound.\n");
        return;
    }
    struct node *target=temp->next;
    temp->next=target->next;
    printf("Deleted element from position %d \n");
    free(target);
    
}

int main() {
    int choice, val;
    while(1) {
        printf("-- Linked List Insertion Menu --\n");
        printf("1. Insert at begining\n");
        printf("2. Delete at begining\n");
        printf("3. Insert at position\n");
        printf("4. Delete at position\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert at begining: ");
                scanf("%d", &val);
                insert_begining(val);
                break;
            case 2:
                delete_begining();
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
                int pos;
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                return 0;
        }
    }
}

