// Construct a binary tree and display its preorder, inorder and postorder traversals

#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node Structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform preorder traversal
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to test the binary tree traversal
int main() {
    // Constructing the binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Displaying the preorder traversal
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Displaying the inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Displaying the postorder traversal
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
