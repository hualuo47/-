#include<bits/stdc++.h>
using namespace std;
struct info{
    int l;
    int r;
};
bool cmp(const info& a,const info& b){
    return a.l<b.l; 
}
int Maxlinecount(vector<info>& arr){
    sort(arr.begin(),arr.end(),cmp);
    priority_queue<int,vector<int>,greater<int>> min_heap;
    int max_num=0;
    for(auto& infos:arr){
        while(!min_heap.empty()&&min_heap.top()<=infos.l){
            min_heap.pop();
        }
        min_heap.push(infos.r);
        max_num=max(max_num,(int)min_heap.size());
    }
    return max_num;
}
