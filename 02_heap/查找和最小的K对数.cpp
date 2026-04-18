#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> min_heap;
        vector<vector<int>> res;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<min(k,n);i++){
            min_heap.emplace(nums1[i]+nums2[0],i,0);
        }
        while(!min_heap.empty()&&res.size()<k){
            auto [sum,i,j]=min_heap.top();
            res.push_back({nums1[i],nums2[j]});
            min_heap.pop();
            if(j+1<m){
                sum=nums1[i]+nums2[j+1];
                min_heap.emplace(sum,i,j+1);
            }
        }
        return res;
    }