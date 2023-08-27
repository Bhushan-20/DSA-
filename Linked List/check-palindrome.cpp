#include<iostream>
#include<vector>
using namespace std;

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

bool checkpalindrome(vector<int> arr){
      int n=arr.size();
      int s=0;
      int e=n-1;
      while(s<=e){
          if(arr[s]!=arr[e]){
              return 0;
          }else{
              s++;
              e--;
          }
      }
      return 1;
  }
 bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        return checkpalindrome(arr);
} 



int main() {
    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    ListNode* current = head;

    // Call the isPalindrome function and print the result
    if (isPalindrome(head)) {
        cout << "Linked list is a palindrome." << endl;
    } else {
        cout << "Linked list is not a palindrome." << endl;
    }

    // Clean up the allocated memory
    
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}