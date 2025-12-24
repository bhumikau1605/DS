#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
} *head = NULL;
int count() {
    struct node* temp = head;
    int i = 0;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return i;
}
struct node* create(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void insert_begin(int value) {
    struct node* newnode = create(value);
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}
void delete_begin() {
    struct node* temp;
    if (head == NULL) {
        printf("Deletion is not possible. List is empty.\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
        printf("Deleted node from beginning.\n");
    }
}
void delete_end() {
    struct node* temp1;
    struct node* temp2;
    if (head == NULL) {
        printf("Deletion is not possible. List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        // Only one node
        free(head);
        head = NULL;
        printf("Deleted node from end.\n");
        return;
    }
    temp1 = head;
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
    printf("Deleted node from end.\n");
}
void delete_pos(int pos) {
    struct node* temp1;
    struct node* temp2;
    int i = 1;
    int length = count();
    if (pos < 1 || pos > length) {
        printf("Deletion not possible. Position out of range.\n");
        return;
    }
    if (pos == 1) {
        delete_begin();
        return;
    }
    temp1 = head;
    while (i < pos) {
        temp2 = temp1;
        temp1 = temp1->next;
        i++;
    }
    temp2->next = temp1->next;
    free(temp1);
    printf("Deleted node at position %d.\n", pos);
}
void delete_spec_value(int key) {
    struct node* temp1 = head;
    struct node* temp2 = NULL;
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (temp1 != NULL && temp1->data == key) {
        head = temp1->next;
        free(temp1);
        printf("Element %d deleted.\n", key);
        return;
    }
    while (temp1 != NULL && temp1->data != key) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1 == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }
    temp2->next = temp1->next;
    free(temp1);
    printf("Element %d deleted.\n", key);
}
void display() {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int ch, pos, value, key;
  printf("NAME: BHUMIKA U \nUSN: 1BM24CS073\n");
    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete at Position\n");
        printf("5. Delete by Value\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_begin(value);
                break;
            case 2:
                delete_begin();
                break;
            case 3:
                delete_end();
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                delete_spec_value(key);
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (ch != 7);
    return 0;
}

