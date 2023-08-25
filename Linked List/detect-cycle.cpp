#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
    int data ;
    Node* next;

    Node(int data){
        this -> data =data;
       this ->next=NULL;
    }

    


};
//Approach 1
/*
bool detectCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    std::map<Node*, bool> visited;
    Node* temp = head;
    while (temp != nullptr) {
        if (visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
} */

//Approach 2 using floyd's cycle detection
Node *detectCycle(Node *head) {
    if (head == NULL)
        return NULL;

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return fast;  
    }

    return NULL;  
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; 

    bool hasCycle = detectCycle(head);
    if (hasCycle) {
        cout << "The linked list contains a cycle." << endl;
    } else {
        cout << "The linked list does not contain a cycle." <<endl;
    }

    // Clean up: Delete the linked list (don't forget to deallocate memory)
    delete head->next->next->next; // Delete nodes in reverse order
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
