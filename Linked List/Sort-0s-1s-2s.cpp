#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};



//Approach 1
/*
Node* sortList(Node *head){
    int countZero=0;
    int countOne=0;
    int countTwo=0;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0)
            countZero++;
        
        else if (temp->data==1)
            countOne++;
        
        else if (temp->data==2)
            countTwo++;
        
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(countZero!=0){
            temp->data=0;
            countZero--;
        }
        else if(countOne!=0){
            temp->data=1;
            countOne--;
        }
        else if(countTwo!=0){
            temp->data=2;
            countTwo--;
        }
        temp=temp->next;
    }
    return head;
}
*/

//Approach 2 = If data replacement is not allowed
void insertAtTail(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
}

Node* sortlist(Node* head){
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onehead=new Node(-1);
    Node* onetail=onehead;
    Node* twohead=new Node(-1);
    Node* twotail=twohead;


    Node* curr=head;
    //create seprate list for 0s,1s,2s
    while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            insertAtTail(zerotail,curr);(zerotail,curr);
        }
        else if(value==1){
            insertAtTail(onetail,curr);
        }
        else if(value==2){
            insertAtTail(twotail,curr);
        }
        curr=curr->next;
    }

    //We have to merge all 3 list now

    if(onehead->next!=NULL){
        //1s list is not empty
        zerotail->next=onehead->next;

    }
    else{
        //1s list is empty
        zerotail->next=twohead->next;
    }

    onetail->next=twohead->next;
    twotail->next=NULL;
    head=zerohead->next;

    //delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

int main() {
    // Creating the linked list with example values: 1 -> 2 -> 0 -> 1 -> 2
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);

    std::cout << "Original List: ";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    head = sortlist(head);

    std::cout << "Sorted List: ";
    current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Clean up the allocated memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}