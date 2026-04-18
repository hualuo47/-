#include<iostream>
using namespace std;
 struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 bool isPalindrome(ListNode* head) {
     if(head==nullptr||head->next==nullptr){
        return true;
     }   
     ListNode* slow=head;
     ListNode* fast=head;
     while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
     }
     bool ans=true;
     ListNode* pre=nullptr;
     ListNode* next=nullptr;
     ListNode* cur=slow;
     while(cur!=nullptr){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
     }
     ListNode* left=head;
     ListNode* right=pre;
     while(left!=nullptr&&right!=nullptr){
        if(left->val!=right->val){
            ans=false;
            break;
        }
        left=left->next;
        right=right->next;
     }
     cur=pre;
     pre=nullptr;
     while(cur!=nullptr){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
     }
     return ans;
    }