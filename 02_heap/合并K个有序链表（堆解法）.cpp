#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  struct ListNode_cmp{
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
  };
 ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,ListNode_cmp> min_heap;
    for(auto& h:lists){
        if(h!=nullptr){
            min_heap.push(h);
        }
    }
    if(min_heap.empty()){
        return nullptr;
    }
        ListNode* h=min_heap.top();
        min_heap.pop();
        ListNode* pre=h;
        if(pre->next!=nullptr){
            min_heap.push(pre->next);
        }
        while(!min_heap.empty()){
            ListNode* cur=min_heap.top();
            min_heap.pop();
            pre->next=cur;
            pre=cur;
            if(cur->next!=nullptr){
                min_heap.push(cur->next);
            }

        }
        return h;

}








