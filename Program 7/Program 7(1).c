#include <stdlib.h>

// Structure for a node in DLL
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// Global head pointer
struct node *head = NULL;

// create a new node
struct node *create(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// insert a node at end
struct node *insert_end(int data)
{
    struct node *newnode = create(data);

    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    struct node *current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = newnode;
    newnode->prev = current;

    return head;
}

// insert a new node to the left of a given node
void insert_left(int new_data, int key_value)
{
    struct node *newnode = create(new_data);

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *current = head;

    while (current != NULL && current->data != key_value)
        current = current->next;

    if (current == NULL)
    {
        printf("Target node %d not found.\n", key_value);
        free(newnode);
        return;
    }

    newnode->next = current;
    newnode->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = newnode;
    else
        head = newnode;

    current->prev = newnode;
}

// delete node with specific key
void del_key(int key)
{
    struct node *current = head;

    while (current != NULL && current->data != key)
        current = current->next;

    if (current == NULL)
    {
        printf("Key not found.\n");
        return;
    }

    // Case 1: deleting head
    if (current->prev == NULL)
    {
        head = current->next;
        if (head != NULL)
            head->prev = NULL;
    }
    // Case 2: middle or last
    else
    {
        current->prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    printf("Element deleted.\n");
}

// search key
void search(int key)
{
    struct node *current = head;
    int pos = 1;

    while (current != NULL && current->data != key)
    {
        current = current->next;
        pos++;
    }

    if (current == NULL)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", pos);
}

// display list
void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = head;
    printf("Doubly Linked List: ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, value, key;
 printf("NAME: BHUMIKA SHRINIVAS TELI \nUSN: 1BM24CS072\n");
    printf("WAP TO CONSTRUCT AND IMPLEMENT OPERATIONS ON DOUBLY LINKED LIST: \n");
    do
    {
        printf("\n1.Insert end\n2.Insert left\n3.Delete\n4.Search\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 2:
                printf("Enter new value and key value: ");
                scanf("%d %d", &value, &key);
                insert_left(value, key);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                del_key(key);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 6);

    return 0;
}
