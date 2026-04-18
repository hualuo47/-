#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
 vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> min_heap;
        int n=nums.size();
        int max_num=INT_MIN;
        for(int i=0;i<n;i++){
            min_heap.push({nums[i][0],i,0});
            max_num=max(max_num,nums[i][0]);
        }
        int best_start=min_heap.top()[0];
        int best_end=max_num;
        while(1){
            auto top=min_heap.top();
            min_heap.pop();
            int lin=top[1],col=top[2];
            int current_start=top[0];
            int current_end=max_num;
            if((current_end-current_start<best_end-best_start)||
            ((current_end-current_start)==(best_end-best_start)&&(current_start<best_start))){
                best_start=current_start;
                best_end=current_end;
            }
            if(col==nums[lin].size()-1){
                break;
            }
            int next_val=nums[lin][col+1];
            min_heap.push({nums[lin][col+1],lin,col+1});
            if(next_val>max_num){
                max_num=next_val;
            }
        }
        return {best_start,best_end};

    }