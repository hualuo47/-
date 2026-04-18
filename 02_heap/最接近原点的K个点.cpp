#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
 vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pair<long long ,vector<int>>> max_heap;
      vector<vector<int>> res;
      for(auto& point:points){
        long x=point[0],y=point[1];
        long long d=x*x+y*y;
        max_heap.emplace(d,point);
        if(max_heap.size()>k){
            max_heap.pop();
        }
      }
      while(!max_heap.empty()){
        res.emplace_back(max_heap.top().second);
        max_heap.pop();
      }
      return res;
    }