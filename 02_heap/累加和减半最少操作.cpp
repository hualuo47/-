#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        double sum=0;
        priority_queue<double> max_heap;
        for(int i=0;i<n;i++){
            sum+=(double)nums[i];
            max_heap.push(nums[i]);
        }
        double res=0;
        int conunt=0;
        while(res<sum/2){
            double num=max_heap.top()/2;
            max_heap.pop();
            max_heap.push(num);
            res+=num;
            count++;
        }
        return count;
    }
};