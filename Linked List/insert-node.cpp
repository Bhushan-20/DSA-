#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};
//Insert Node at head
void InsertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;


}
//Insert Node at Tail
void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail-temp;

}
//Insert Node at any position
void InsertAtAnyPosition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        InsertAtHead(head,d);
        return ;
    }
    Node *temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        InsertAtTail(head,d);
        return ;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}
//Traversing a Linked list
void print(Node* head){
    Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}

int main()
{
    Node * node1=new Node(10);
    

    Node* head = node1;
    Node * tail=node1;

    print(head);

    InsertAtHead(head,9);
    InsertAtHead(head,8);
    InsertAtHead(head,7);
    InsertAtHead(head,6);

    print(head);

    cout<<"Head = "<<head->data<<endl;
    cout<<"Tail = "<<tail->data<<endl;

    InsertAtAnyPosition(tail,head,2,22);
    print(head);

    return 0;

}