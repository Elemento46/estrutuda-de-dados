#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int data;                
    struct Node *next;       
} Node;


Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; 
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }