#include <iostream>

template <typename T>
struct LinkedListNode {
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T value) : data(value), next(nullptr) {}
};

template <typename T>
LinkedListNode<T> *reverseLinkedList(LinkedListNode<T> *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    LinkedListNode<T> *previous = nullptr;
    LinkedListNode<T> *current = head;
    while (current != nullptr) {
        LinkedListNode<T> *forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    return previous;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode<int> *head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    std::cout << "Original linked list: ";
    LinkedListNode<int> *current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Reversing the linked list
    LinkedListNode<int> *reversedHead = reverseLinkedList(head);

    std::cout << "Reversed linked list: ";
    current = reversedHead;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Clean up the memory by deleting the linked list nodes
    current = reversedHead;
    while (current != nullptr) {
        LinkedListNode<int> *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
