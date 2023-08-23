#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** ptr, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*ptr == NULL) {
        *ptr = newNode;
        return;
    }

    struct Node* curr = *ptr;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
}

void deleteNode(struct Node** ptr, int value) {
    struct Node* curr = *ptr;
    struct Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data == value) {
            if (prev == NULL) { // head
                *ptr = curr->next;
                free(curr);
                curr = *ptr;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////
void addNodeAtIndex(struct Node** ptr, int value, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

	
    if (index == 0 || *ptr == NULL) { //first node
        newNode->next = *ptr;
        *ptr = newNode;
        return;
    }

    struct Node* curr = *ptr;
    struct Node* prev = NULL;
    int count = 0;

    while (curr != NULL && count < index) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (count == index) {
        prev->next = newNode;
        newNode->next = curr;
    } else {
        printf("Invalid index. Node not added.\n");
        free(newNode);
    }
}
////////////////////////////////////////////////////////////////////////////////////////
void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void main() {
    struct Node* head = NULL;
    int input, value, index;

    while (1) {
        printf("Enter 0 to add a node, 1 to delete node, 2 to add node at index, 3 to print the linked list, or 4 to exit: ");
        scanf("%d", &input);

        switch (input) {
        case 0:
            printf("Enter the value to add: ");
            scanf("%d", &value);
            addNode(&head, value);
            break;

        case 1:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;

        case 2:
            printf("Enter the value to add: ");
            scanf("%d", &value);
            printf("Enter the index to add at: ");
            scanf("%d", &index);
            addNodeAtIndex(&head, value, index);
            break;

        case 3:
            printf("Linked List: ");
            printList(head);
            break;

        case 4:
            printf("Exiting the program.\n");
            return;

        default:
            printf("Incorrect entry.\n");
            break;
        }
    }

    while (head != NULL) {
        struct Node* curr = head;
        head = head->next;
        free(curr);
    }

}
