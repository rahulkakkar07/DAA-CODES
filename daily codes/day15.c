#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to detect cycle
int detectCycle(struct Node* head) {

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        // Slow moves one step
        slow = slow->next;

        // Fast moves two steps
        fast = fast->next->next;

        // If they meet, cycle exists
        if (slow == fast) {
            return 1;
        }
    }

    // If fast reaches NULL, no cycle exists
    return 0;
}

int main() {

    // Creating linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Creating a cycle:
    // Node 5 points to Node 3
    head->next->next->next->next->next = head->next->next;

    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    }
    else {
        printf("No cycle detected in the linked list.\n");
    }

    return 0;
}