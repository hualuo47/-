#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 ListNode* Find(ListNode* s,int step){
    while(s->next!=nullptr&&--step!=0){
        s=s->next;
    }
    return s;
}
  ListNode* start=nullptr;
  ListNode* end=nullptr;
  void merge(ListNode* l1,ListNode* r1,ListNode* l2,ListNode* r2){
    ListNode* pre=nullptr;
    if(l1->val<=l2->val){
        start=l1;
        pre=l1;
        l1=l1->next;
    }
    else{
        start=l2;
        pre=l2;
        l2=l2->next;
    }
    while(l1!=nullptr&&l2!=nullptr){
        if(l1->val<=l2->val){
            pre->next=l1;
            pre=l1;
            l1=l1->next;
        }
        else{
            pre->next=l2;
            pre=l2;
            l2=l2->next;
        }
    }
    if(l1!=nullptr){
        pre->next=l1;
        end=r1;
    }
    else{
        pre->next=l2;
        end=r2;
    }
}
  ListNode* sortList(ListNode* head) {
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    int n=0;
    ListNode* cur=head;
    while(cur!=nullptr){
        cur=cur->next;
        n++;
    }
    ListNode* l1=nullptr;
    ListNode* r1=nullptr;
    ListNode* l2=nullptr;
    ListNode* r2=nullptr;
    ListNode* LastEnd=nullptr;
    ListNode* next=nullptr;
    for(int step=1;step<n;step*=2){
        l1=head;
        r1=Find(l1,step);
        l2=r1->next;
        r2=Find(l2,step);
        next=r2->next;
        r1->next=nullptr;
        r2->next=nullptr;
        merge(l1,r1,l2,r2);
        head=start;
        LastEnd=end;
        while(next!=nullptr){
            l1=next;
            r1=Find(l1,step);
            l2=r1->next;
            if(l2==nullptr){
                LastEnd->next=l1;
                break;
            }
            r2=Find(l2,step);
            next=r2->next;
            r1->next=nullptr;
            r2->next=nullptr;
            merge(l1,r1,l2,r2);
            LastEnd->next=start;
            LastEnd=end;
        }
    }
    return head;

    }