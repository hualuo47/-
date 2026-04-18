#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> min_heap;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            min_heap.psuh({matrix[i][0],i,0});
        }
        int res=0;
        for(int i=0;i<k;i++){
            auto top=min_heap.top();
            min_heap.pop();
            res=top[0];
            int lin=top[1],col=top[2];
            if(col+1<n){
                min_heap.push({matrix[lin][col+1],lin,col+1});
            }
        }
        return res;
    }