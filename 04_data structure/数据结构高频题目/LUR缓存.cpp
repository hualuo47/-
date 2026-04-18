#include<iostream>
#include<unordered_map>
using namespace std;
class LRUCache {
struct DoubleNode{
    int key;
    int val;
    DoubleNode* last;
    DoubleNode* next;
    DoubleNode(int k,int v):key(k),val(v),last(nullptr),next(nullptr){}
};
class DoubleList {
    private:
        DoubleNode* head;
        DoubleNode* tail;
    public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    void addNode(DoubleNode* newNode){
        if(newNode==nullptr){
            return ;
        }
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->last=tail;
            tail=newNode;
        }
    }
    void moveNode(DoubleNode* node){
        if(tail==node){
            return ;
        }
        if(head==node){
            head=node->next;
            if(head){
                head->last=nullptr;
            }
        }
        else{
            node->last->next=node->next;
            node->next->last=node->last;
        }
        tail->next=node;
        node->next=nullptr;
        node->last=tail;
        tail=node;
    }
    DoubleNode* removeNode(){
        if(head==nullptr){
            return nullptr;
        }
        DoubleNode* ans=head;
        if(head==tail){
            head=nullptr;
            tail=nullptr;
        }
        else{
            head=ans->next;
            ans->next=nullptr;
            head->last=nullptr;
        }
         return ans;
    }

  };
   unordered_map<int, DoubleNode*> keyNodeMap;
    DoubleList* nodeList;                       
    int capacity;                    
  public:
   LRUCache(int capacity) {
        this->capacity = capacity;    
        nodeList = new DoubleList();
    }
     ~LRUCache() {
        while (true) {
            DoubleNode* node = nodeList->removeNode();
            if (node == nullptr) break;
            delete node;
        }
        delete nodeList; 
    }

    int get(int key) {
        if(keyNodeMap.find(key)!=keyNodeMap.end()){
            DoubleNode* ans=keyNodeMap[key];
            nodeList->moveNode(ans);
            return ans->val;
        }
        return -1;
    }
    void put(int key, int value) {
     if(keyNodeMap.find(key)!=keyNodeMap.end()){
        DoubleNode* node=keyNodeMap[key];
        node->val=value;
        nodeList->moveNode(node);
        return;
     } 
        if(keyNodeMap.size()==capacity){
           DoubleNode*deadNode=nodeList->removeNode();
           if(deadNode!=nullptr){
            keyNodeMap.erase(deadNode->key);
            delete deadNode;
           }
        }
         DoubleNode* newNode=new DoubleNode(key,value);
            keyNodeMap[key]=newNode;
            nodeList->addNode(newNode);
    }
};


