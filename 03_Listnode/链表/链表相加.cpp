
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x=0):val(x),next(nullptr){}
};
ListNode8* mergelists(ListNode* h1,ListNode* h2){
    ListNode* ans=nullptr;
    ListNode* cur=nullptr;
    int carry=0;
    while(h1!=nullptr||h2!=nullptr){
        int val1=(h1!=nullptr)?h1->val:0;
        int val2=(h2!=nullptr)?h2->val:0;
        int sum=val1+val2+carry;
        int val=sum%10;
        carry=sum/10;
        ListNode* NewNode=new ListNode(val);
        if(ans==nullptr){
            ans=NewNode;
            cur=ans;
        }
        else{
            cur->next=NewNode;
            cur=cur->next;
        }
        if(h1!=nullptr) h1=h1->next;
        if(h2!=nullptr) h2=h2->next;
    }
    if(carry==1){
        cur->next=new ListNode(1);
    }
    return ans;
}