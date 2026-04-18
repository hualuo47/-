#include<iostream>
#include<vector>
#include<queue>
using namespace std;
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if(heights.empty()) return 0;
        int n=heights.size();
        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(int i=0;i<n-1;i++){
           int diff=heights[i+1]-heights[i];
           if(diff<0){
            continue;
           }
           min_heap.push(diff);
           if(min_heap.size()>ladders){
            bricks-=min_heap.top();
            min_heap.pop();
           }
           if(bricks<0){
            return i;
           }
        }
        return n-1;
    }



