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
    int choice;
    int key;
    do{
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Get Parent\n5. Display Inorder\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(&root, key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:    
                printf("Enter the key to search: ");
                scanf("%d", &key);
                Node* node = search(root, key);
                if (node != NULL){
                    printf("Key found\n");    
                }else{
                    printf("Key not found\n");
                }
                break;
            case 4:
                printf("Enter the key to get parent: ");
                scanf("%d", &key);
                Node* parent = getParent(root, key);
                if (parent != NULL){
                    printf("Parent of %d is %d\n", key, parent->key);
                }else{
                    printf("Key not found\n");
                }
                break;
            case 5:
                printf("Inorder traversal: ");
                DisplayInorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");       
        }
    }while(choice != 6);
    return 0;
}
