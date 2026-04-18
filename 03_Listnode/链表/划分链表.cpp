#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
   ListNode* partition(ListNode* head, int x) {
        ListNode* lefthead=nullptr;ListNode* lefttail=nullptr;
        ListNode* righthead=nullptr;ListNode* righttail=nullptr;
        ListNode* next=nullptr;
        while(head!=nullptr){
            next=head->next;
            head->next=nullptr;
            if(head->val<x){
                if(lefthead==nullptr){
                    lefthead=head;
                }
                else{
                    lefttail->next=head;
                }
                lefttail=head;
            }
            else{
                if(righthead==nullptr){
                    righthead=head;
                }
                else{
                    righttail->next=head;
                }
                righttail=head;
            }
            head=next;
        }
        if(lefthead==nullptr){
            return righthead;
        }
        lefttail->next=righthead;
        return lefthead;
    }