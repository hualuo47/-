#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* cur=head;
        Node* next=nullptr;
        while(cur!=nullptr){
            next=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=next;
            cur=next;
        }
        cur=head;
        Node* copy=nullptr;
        while(cur!=nullptr){
           next=cur->next->next;
           copy=cur->next;
           copy->random=cur->random!=nullptr?cur->random->next:nullptr; 
           cur=next;
        }
        cur=head;
        Node* ans=head->next;
        while(cur!=nullptr){
            next=cur->next->next;
            copy=cur->next;
            cur->next=next;
            copy->next=copy->next!=nullptr?copy->next->next:nullptr;
            cur=next;
        }
        return ans;

    }
