#include <iostream>

class ListNode {
    public:
    int val;
    ListNode* prev;
    ListNode* next;

    //constructor
    ListNode(int d ) {
        this-> val = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* current = head;
    while (current->next != nullptr) {
        if (current->val == current->next->val) {
            ListNode* nodetodelete = current->next;
            current->next = current->next->next;
            delete nodetodelete;
        }
        else {
            current = current->next;
        }
    }
    return head;
}


void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    std::cout << "Original linked list: ";
    printList(head);

    head = deleteDuplicates(head);

    std::cout << "Linked list after deleting duplicates: ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
