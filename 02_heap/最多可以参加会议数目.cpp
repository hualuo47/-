#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 int maxEvents(vector<vector<int>>& events) {
     sort(events.begin(),events.end());
        int n=events.size();
      priority_queue<int,vector<int>,greater<int>> min_heap;
      int day=0,count=0;
      int i=0;
      while(i<n||!min_heap.empty()){
        if(min_heap.empty()){
            day=events[i][0];
        }
        while(i<n&&events[i][0]<=day){
            min_heap.push(events[i][1]);
            i++;
        }
        while(!min_heap.empty()&&day>min_heap.top()){
            min_heap.pop();
        }
        if(!min_heap.empty()){
            min_heap.pop();
            count++;
        }
        day++;
      }
      return count;
    } 