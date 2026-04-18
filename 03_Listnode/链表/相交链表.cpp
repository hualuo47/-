#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==nullptr||headB==nullptr){
        return nullptr;
    }
        int k=0;
        ListNode* h1=headA;
        ListNode* h2=headB;
        while(h1->next!=nullptr){
            h1=h1->next;
            k++;
        }
        while(h2->next!=nullptr){
            h2=h2->next;
            k--;
        }
        if(h1!=h2){
            return nullptr;
        }
        if(k>=0){
            h1=headA;
            h2=headB;
        }
        else{
            h1=headB;
            h2=headA;
        }
        k=abs(k);
        while(k--!=0){
            h1=h1->next;
        }
        while(h1!=h2){
            h1=h1->next;
            h2=h2->next;
        }
        return h1;

    }
