#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()){
        return {};
    }
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> min_heap;
    vector<vector<int>> res;
    for(auto& interval:intervals){
        min_heap.push(interval);
    }
    res.push_back(min_heap.top());
    min_heap.pop();
    while(!min_heap.empty()){
        auto last=min_heap.top();
        min_heap.pop();
        auto&  cur=res.back();
        if(last[0]<=cur[1]){
            cur[1]=max(last[1],cur[1]);
        }
        else{
            res.push_back(last);
        }
    }
    return res;
}