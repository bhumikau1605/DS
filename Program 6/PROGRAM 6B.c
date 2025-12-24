#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *st=NULL;
struct node * q_front=NULL;
struct node * q_rear=NULL;
void push(int value)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n Memory allocation failed!\n");
        return;
    }
    newnode->data=value;
    newnode->next=st;
    st=newnode;
    printf("\n%d pushed onto the stack\n",value);
}
int pop()
{
    if(st==NULL)
    {
        printf("\nStack underflow: Stack is empty\n");
        return;
    }
    struct node* temp=st;
    int val=temp->data;
    st=st->next;
    free(temp);
    printf("%d popped from stack\n",val);
    return val;
}
int peek_stack()
{
    if(st==NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    return st->data;
}
void display_stack()
{
    if(st==NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    struct node *current=st;
    printf("Stack elements: \n");
    while(current!=NULL)
    {
        printf("%d",current->data);
        current=current->next;
    }
    printf("\n");
}
void enqueue(int value)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n Memory allocation failed!\n");
        return;
    }
    newnode->data=value;
    newnode->next=NULL;
    if(q_front==NULL)
    {
        q_front=newnode;
        q_rear=newnode;
    }
    else
    {
        q_rear->next=newnode;
        q_rear=newnode;
    }
    printf("%d enqueued to queue\n",value);
}
int dequeue()
{
    if(q_front==NULL)
    {
        printf("Queue underflow\n");
        return;
    }
    struct node *temp=q_front;
    int value=temp->data;
    q_front=q_front->next;
    if(q_front==NULL)
    {
        q_rear=NULL;
    }
    free(temp);
    printf("%d dequeued from queue\n",value);
    return;
}
int peek_queue()
{
    if(q_front==NULL)
    {
        printf("Queue underflow\n");
        return -1;
    }
    return q_front->data;
}
void display_queue()
{
    if(q_front==NULL)
    {
        printf("Queue underflow\n");
        return;
    }
    struct node *current=q_front;
    printf("Queue elements\n");
    while(current!=NULL)
    {
        printf("%d",current->data);
        current=current->next;
    }
    printf("\n");
}
int main()
{
    int opt,val,del,p;
    printf("NAME: BHUMIKA SHRINIVAS TELI \nUSN: 1BM24CS072\n");
    printf("\n WAP TO IMPLEMENT STACK AND QUEUE USING LINKED LIST\n");
    printf("--MENU-- \n 1. Push an element\n 2. Pop an element \n 3.Peek an element from the stack\n 4. Display the stack\n 5. Enqueue an element\n 6. Dequeue an element\n 7.Peek an element \n 8. Display the queue\n 9.Exit\n ");
    while(1)
    {
        printf("\nEnter your choice: \n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter number to be inserted onto the stack: \n");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
               del=pop();
               break;
        case 3:
            p=peek_stack();
            printf("\n The number peeked is: %d",p);
            break;
        case 4:
            printf("\n Elements of the stack: \n");
            display_stack();
            break;
        case 5:
            printf("\nEnter the number to be enqueued: \n");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 6:
            del=dequeue();
            printf("\n The number dequeued is: %d",del);
            break;
        case 7:
            p=peek_queue();
            printf("\n The number peeked is: %d\n",p);
            break;
        case 8:
            printf("The elements are: ");
            display_queue();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!");
        }
    }
    return 0;
}
