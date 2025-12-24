#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
struct node *create(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
struct node *ins_end(int data)
{
    struct node *newnode=create(data);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    struct node *current=head;
    while(current!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
    newnode->prev=current;
    return head;
}
void ins_left(int data, int key)
{
    struct node *newnode=create(data);
    struct node *current=head;
    while(current!=NULL && current->data!=key)
    {
        current=current->next;
    }
    newnode->next=current;
    newnode->prev=current->prev;
    current->prev=newnode;
}
void search(int key)
{
    struct node *current=head;
    int pos=1;
    while(current!=NULL && current->data!=key)
    {
        pos++;
        current=current->next;
    }
    if(current==NULL)
    {
        printf("Key not found!\n");
    }
    printf("Key found at %d\n",pos);
}
}
void del_key(int key)
{
    struct node *current=head;
    while(current!=NULL && current->data!=key)
    {
        current=current->next;
    }
    if(current==NULL)
    {
        printf("Key not found\n");
    }
    else
    {
        current->prev->next=current->next;
        current->next->prev=current->prev;
        free(current);
        printf("%d Element is deleted!\n",key);
    }
}
void display()
{
    struct node *current=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    while(current!=NULL)
    {
        printf("%d <-> ",current);
        current=current->next;
    }
    printf("NULL\n");
}
void main()
{
    int ch, key, val;
    printf("--MENU-- \n 1. Insert at end\n 2. Insert to the left of a node\n 3. Search\n 4. Delete a node based on a specific key value\n 5. Display the list\n 6. Exit\n");
    while(1)
    {
        printf("Enter your choice: \n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter the value you want to insert: ");
            scanf("%d",&val);
            ins_end(val);
            break;
        case 2:
            printf("\n Enter the value you want to insert to the left of a node: ");
            scanf("%d",&val);
            printf("\n Enter the node: ");
            scanf("%d",&key);
            ins_left(val,key);
            break;
        case 3:
            printf("\n Enter the value you want to search: ");
            scanf("%d",&val);
            search(val);
            break;
        case 4:
            printf("\n Enter the value you want to delete: ");
            scanf("%d",&val);
            del_key(val);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("\n Wrong choice! Enter again!");
        }
    }
}
