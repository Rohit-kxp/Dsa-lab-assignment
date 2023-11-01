// Implement a double-ended queue using a linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Double-ended queue structure
typedef struct {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty deque
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(Deque* deque) {
    return deque->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(Deque* deque, int data) {
    Node* newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to insert an element at the rear of the deque
void insertRear(Deque* deque, int data) {
    Node* newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to delete an element from the front of the deque
void deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    Node* frontNode = deque->front;
    deque->front = deque->front->next;
    
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    
    free(frontNode);
}

// Function to delete an element from the rear of the deque
void deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    Node* rearNode = deque->rear;
    deque->rear = deque->rear->prev;
    
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    
    free(rearNode);
}

// Function to display the elements in the deque
void display(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = deque->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to test the deque implementation
int main() {
    Deque* deque = createDeque();

    insertFront(deque, 10);
    insertFront(deque, 20);
    insertRear(deque, 30);
    insertRear(deque, 40);

    printf("Deque elements: ");
    display(deque);

    deleteFront(deque);
    deleteRear(deque);

    printf("Deque elements after deletions: ");
    display(deque);

    return 0;
}
