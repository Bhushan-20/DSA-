#include<iostream>
#include<vector>
#include<stack>
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
//approach 1->Brute force
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

//Approach2 -> Better Solution
bool isPalindromeOrNot(ListNode* head) {
    stack<int> st;
    ListNode* temp = head;

    // Push all elements of the linked list onto the stack
    while (temp != NULL) {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;

    // Compare the elements from the stack with the linked list
    while (!st.empty() && temp != NULL) {
        if (st.top() != temp->val) {
            return false;
        }
        st.pop();
        temp = temp->next;
    }

    return true;
}


//Approach2
/*ListNode* getMid(ListNode* head ) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode *head)
    {
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        ListNode* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->val != head1->val) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
    }*/




int main() {
    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    ListNode* current = head;

    // Call the isPalindrome function and print the result
    if (isPalindromeOrNot(head)) {
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