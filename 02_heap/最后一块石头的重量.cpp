#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for(auto& s:stones){
            max_heap.push(s);
        }
        while(max_heap.size()>1){
            int y=max_heap.top();
            max_heap.pop();
            int x=max_heap.top();
            max_heap.pop();
            if(y-x!=0){
                max_heap.push(y-x);
            }
        }
        if(max_heap.empty()){
            return 0;
        }
        else{
            return max_heap.top();
        }
    }