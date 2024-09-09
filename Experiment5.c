#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right, *parent;
} Node;

Node* newNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

Node* createBST() {
    return NULL;
}

void insert(Node** root, int key) {
    Node* node = newNode(key);
    Node* y = NULL;
    Node* x = *root;

    while (x != NULL) {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;

    if (y == NULL)
        *root = node;
    else if (node->key < y->key)
        y->left = node;
    else
        y->right = node;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

Node* minimum(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* delete(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minimum(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}

Node* getParent(Node* root, int key) {
    Node* node = search(root, key);
    if (node != NULL)
        return node->parent;
    return NULL;
}

void DisplayInorder(Node* root) {
    if (root != NULL) {
        DisplayInorder(root->left);
        printf("%d ", root->key);
        DisplayInorder(root->right);
    }
}

int main() {
    Node* root = createBST();

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of the BST: ");
    DisplayInorder(root);
    printf("\n");

    printf("Deleting 20\n");
    root = delete(root, 20);
    printf("Inorder traversal after deleting 20: ");
    DisplayInorder(root);
    printf("\n");

    printf("Parent of 60: %d\n", getParent(root, 60)->key);

    return 0;
}
