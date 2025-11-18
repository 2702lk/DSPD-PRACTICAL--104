#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}
void search(struct Node* root, int key) {
    if (root == NULL)
        printf("NULL (Not Found)\n");
    else if (root->data == key)
        printf("Found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL)
        return NULL;
    if (root->data == key && root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    root->left = deleteLeaf(root->left, key);
    root->right = deleteLeaf(root->right, key);
    return root;
}
int main() {
    struct Node* root = NULL;
    int choice, val, key;
    while (1) {
        printf("\n1.Search\n2.Insert\n3.Delete Leaf\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 3:
                printf("Enter leaf node to delete: ");
                scanf("%d", &key);
                root = deleteLeaf(root, key);
                printf("Leaf node deleted if found.\n");
                break;
            case 4:
                return 0;
        }
    }
}

