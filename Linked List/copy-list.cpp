#include<iostream>
#include<unordered_map>
using namespace std;


class Node{
    public:
    int data ;
    Node* next;
    Node* random;

    Node(int data){
        this -> data =data;
        this ->next=NULL;
        this->random=NULL;
    }

    


};



void insertAtTail(Node* &head,Node* &tail,int d){
        Node* newnode = new Node(d);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            return;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }

Node *copyList(Node *head)
    {
        /*
        T.C=O(n) S.C=O(n)
        Step1=Create a clone list
        Node* clonehead=NULL;
        Node* cloneTail=NULL;
        
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(clonehead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        Step2=create a map;
        unordered_map<Node*,Node*> oldtonew;
        Node* originalNode=head;
        Node* cloneNode=clonehead;
        while(originalNode!=NULL && cloneNode!=NULL){
            oldtonew[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        originalNode=head;
        cloneNode=clonehead;
        
        while(originalNode!=NULL){
            cloneNode->random=oldtonew[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return clonehead;
        */
       
       //T.C=O(n) S.C=O(1)
        // Step1=Create a clone list
        Node* clonehead=NULL;
        Node* cloneTail=NULL;
        
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(clonehead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        
        //Step2=cloneNodes add in between Original Nodes
        
        Node* originalNode=head;
        Node* cloneNode=clonehead;
        while(originalNode!=NULL && cloneNode!=NULL){
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;
            
            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
        }
        
        //step3=Random pointer copy 
        Node* curr=head;
        while(curr!=NULL){
            if(curr->next!=NULL){
               curr -> next -> random = curr->random ? curr -> random -> next : curr->random; 
            }   
            curr=curr->next->next;
        }
        
        //step4=revert changes of step2
        originalNode=head;
        cloneNode=clonehead;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next=cloneNode->next;
             originalNode=originalNode->next;
             if(originalNode!=NULL){
             cloneNode->next=originalNode->next;
             
            }
            cloneNode=cloneNode->next;
        }
        
        return clonehead;
        
        
}

    
void printListWithRandom(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        int randomData = (temp->random) ? temp->random->data : -1;
        cout << "Node " << temp->data << ", Random " << randomData << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Create original linked list
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    // Assign random pointers
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head;

    cout << "Original list with random pointers:" << endl;
    printListWithRandom(head);

    // Copy the linked list
    Node* clonedHead = copyList(head);

    cout << "Cloned list with random pointers:" << endl;
    printListWithRandom(clonedHead);

    return 0;
}