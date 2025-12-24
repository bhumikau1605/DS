#include<stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void display(struct node* root) {
    printf("\nElements in the Tree (Inorder Display): ");
    inorder(root);
    printf("\n");
}
int main() {
    struct node* root = NULL;
    int n, value;
    printf("Name: BHUMIKA U \n USN: 1BM24CS073");
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nIn-Order Traversal: ");
    inorder(root);

    printf("\nPre-Order Traversal: ");
    preorder(root);

    printf("\nPost-Order Traversal: ");
    postorder(root);

    display(root);

    return 0;
}

