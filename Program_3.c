#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* last = NULL;

void create(int);
void display();
void main(){
    int n,m,i;
    printf("Enter the no of nodes: ");
    scanf("%d",&n);
    for(i=0;i <n;i++){
        printf("Enter the data: ");
        scanf("%d",&m);
        create(m);
    }
    display();
}

void create(int v){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = v;
    t->next = NULL;
    if(head == NULL){
        head = t;
        last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

void display(){
    struct node *p;
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    p = head;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}
