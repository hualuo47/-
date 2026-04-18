#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
 vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
       int m=queries.size();
       int n=intervals.size(); 
       vector<int> ans(m,-1);
       vector<pair<int,int>> que;
       for(int i=0;i<m;i++){
        que.push_back({queries[i],i});
       }
       sort(que.begin(),que.end());
       sort(intervals.begin(),intervals.end());
       int i=0;
       for(auto& q:que){
        int x=q.first;
        int id=q.second;
        while(i<n&&intervals[i][0]<=x){
            int l=intervals[i][0];
            int r=intervals[i][1];
            int res=r-l+1;
            min_heap.emplace(res,r);
            i++;
        }
        while(!min_heap.empty()&&min_heap.top().second<x){
            min_heap.pop();
        }
        if(!min_heap.empty()){
            ans[id]=min_heap.top().first;
        }
       }
       return ans;
    }