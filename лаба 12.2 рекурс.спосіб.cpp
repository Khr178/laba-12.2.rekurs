#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node*& head, int value) {
    if (head == NULL) {
        head = createNode(value);
        return;
    }
    insertNode(head->next, value);
}

void insertNode(Node*& current, int value) {
    if (current == NULL) {
        current = createNode(value);
        return;
    }
    insertNode(current->next, value);
}

void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        return;
    }
    if (head->data == value) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
        deleteNode(head, value);
    }
    else {
        deleteNode(head->next, value);
    }
}

int main() {
    Node* myList = NULL;
    insertNode(myList, 5);
    insertNode(myList, 2);
    insertNode(myList, 8);
    insertNode(myList, 3);
    cout << "Original List: ";
    
    deleteNode(myList, 8);
    cout << "List after deleting 8: ";
    
    deleteNode(myList, 5);
    cout << "List after deleting 5: ";
    
    return 0;
}