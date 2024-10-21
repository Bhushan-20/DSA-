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
    Node* addNumbers(Node* list1, Node* list2) {
        int carry = 0;
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;

        while (list1 != NULL || list2 != NULL || carry != 0) {
            int sum = carry;
            if (list1 != NULL) {
                sum += list1->data;
                list1 = list1->next;
            }
            if (list2 != NULL) {
                sum += list2->data;
                list2 = list2->next;
            }

            carry = sum / 10;
            Node* newNode = new Node(sum % 10);
            curr->next = newNode;
            curr = curr->next;
        }

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

    // Insert elements into list1 (representing number 342)
    insertAtTail(list1, 2);
    insertAtTail(list1, 4);
    insertAtTail(list1, 3);

    // Insert elements into list2 (representing number 465)
    insertAtTail(list2, 5);
    insertAtTail(list2, 6);
    insertAtTail(list2, 4);

    // Print the two lists
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    // Add the two numbers represented by the lists
    Node* result = solution.addNumbers(list1, list2);

    // Print the result list
    cout << "Result List: ";
    printList(result);

    return 0;
}
