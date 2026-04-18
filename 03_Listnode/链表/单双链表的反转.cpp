/*#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* nextNode):val(x),next(nextNode);
};
ListNode* reseversList(ListNode* head){
    ListNode* pre=nullptr;
    ListNode* next=nullptr;
    while(head!=nullptr){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}*/
//单链表反转

/*#include<iostream>
struct DoubleListNode{
    int value;
    DoubleListNode* last;
    DoubleListNode* next;
    DoubleListNode(int v):value(v),last(nullptr),next(nullptr){}
};
DoubleListNode*reversedDoublelistNode(DoubleListNode* head){
    DoubleListNode* next=nullptr;
    DoubleListNode*pre=nullptr;
    while(head!=nullptr){
        next=head->next;
        head->next=pre;
        head->last=next;
        pre=head;
        head=next;
    }
    return pre;
}*/
//双链表反转

//单链表反转