#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Function to insert at beginning
struct node *insert_beg(struct node *head, int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    return newnode;
}

// Function to display list
void display(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Reverse linked list
struct node *reverse_list(struct node *head) {
    struct node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Sort list using your earlier method (swapping data)
struct node *sort_list(struct node *head) {
    struct node *temp1 = head;
    struct node *temp2;

    while (temp1 != NULL) {
        temp2 = temp1->next;

        while (temp2 != NULL) {
            if (temp1->data > temp2->data) {
                int m = temp1->data;
                temp1->data = temp2->data;
                temp2->data = m;
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return head;
}

// Concatenate two lists
struct node* concat_lists(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node *current = head1;
    while (current->next != NULL)
        current = current->next;

    current->next = head2;

    return head1;
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int m, n, val, i;
      printf("NAME: BHUMIKA SHRINIVAS TELI \nUSN: 1BM24CS072\n");
    printf("\nWAP TO CONSTRUCT A LINKED LIST AND MERGE,SORT IT \n");
    printf("Enter number of nodes in List 1 and List 2:\n");
    scanf("%d %d", &m, &n);

    // Create first list
    printf("Enter values for List 1:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        head1 = insert_beg(head1, val);
    }

    printf("List 1 is: ");
    display(head1);

    // Create second list
    printf("Enter values for List 2:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        head2 = insert_beg(head2, val);
    }

    printf("List 2 is: ");
    display(head2);

    // Reverse List 1
    head1 = reverse_list(head1);
    printf("Reversed List 1 is: ");
    display(head1);

    // Sort List 2 using your swap logic
    head2 = sort_list(head2);
    printf("Sorted List 2 is: ");
    display(head2);

    // Concatenate List 1 and List 2
    struct node *concat_head = concat_lists(head1, head2);
    printf("Concatenated List is: ");
    display(concat_head);

    return 0;
}
