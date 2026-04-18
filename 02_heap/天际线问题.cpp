#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int,int>> max_heap;
        vector<vector<int>> res;
        vector<int> bul;
        for(auto& buliding:buildings){
            bul.push_back(buliding[0]);
            bul.push_back(buliding[1]);
        }
        sort(bul.begin(),bul.end());
        int n=buildings.size();
        int i=0;
        int last_n=-1;
        for(auto& b:bul){
            while(i<n&&buildings[i][0]<=b){
                max_heap.emplace(buildings[i][2],buildings[i][1]);
                i++;
            }
            while(!max_heap.empty()&&max_heap.top().second<=b){
                max_heap.pop();
            }
            int max_n=max_heap.empty()?0:max_heap.top().first;
            if(max_n!=last_n){
                res.push_back({b,max_n});
                last_n=max_n;
            }
        }
        return res;
    } 