#include<iostream>
using namespace std;
struct ListNode {
       int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode* teamEnd(ListNode* s,int k){
    while(s!=nullptr&&--k!=0){
        s=s->next;
    }
    return s;
}
ListNode* reserve(ListNode* s,ListNode* e){
    e=e->next;
    ListNode* cur=s;
    ListNode* pre=nullptr;
    ListNode* next=nullptr;
    while(cur!=e){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    s->next=e;
    return s;
}
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start=head;
        ListNode* end=teamEnd(start,k);
        if(end==nullptr){
            return head;
        }
        reserve(start,end);
        head=end;
        ListNode* LastTail=start;
        while(LastTail->next!=nullptr){
            start=LastTail->next;
            end=teamEnd(start,k);
            if(end==nullptr){
                return head;
            }
            reserve(start,end);
            LastTail->next=end;
            LastTail=start;
        }
        return head;
    }
