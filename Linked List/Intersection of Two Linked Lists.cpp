#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Utility function to append nodes to the list
void append(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

class Solution {
public:
    Node *getIntersectionNode(Node *headA, Node *headB) {
        Node* temp1 = headA;
        Node* temp2 = headB;
        while (temp1 != temp2) {
            temp1 = (temp1 != NULL) ? temp1->next : headB;
            temp2 = (temp2 != NULL) ? temp2->next : headA;
        }
        return temp1;
    }
};

int main() {
    Node* headA = NULL;
    Node* headB = NULL;

    // Creating first linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    append(headA, 1);
    append(headA, 2);
    append(headA, 3);
    append(headA, 4);
    append(headA, 5);

    // Creating second linked list: 9 -> 8 -> 3 -> 4 -> 5 -> NULL
    append(headB, 9);
    append(headB, 8);
    
    // Manually linking the intersection point to node with value 3
    headB->next->next = headA->next->next;

    Solution solution;
    Node* intersection = solution.getIntersectionNode(headA, headB);

    // Displaying the lists
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}
