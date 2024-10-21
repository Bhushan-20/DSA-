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

class Solution {
    public:
    Node* mergelist(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while (list1 != NULL && list2 != NULL) {
            if (list1->data < list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1) temp->next = list1;
        else temp->next = list2;

        return dummyNode->next;
    }
};

// Function to insert nodes at the end of the list
void insertAtTail(Node* &head, int data) {
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

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Solution solution;

    // Insert elements into list1
    insertAtTail(list1, 1);
    insertAtTail(list1, 3);
    insertAtTail(list1, 5);

    // Insert elements into list2
    insertAtTail(list2, 2);
    insertAtTail(list2, 4);
    insertAtTail(list2, 6);

    // Print the two lists
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    // Merge the two sorted lists
    Node* mergedList = solution.mergelist(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
