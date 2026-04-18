#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void f(vector<int>& nums,int i,vector<int>& path,int size,vector<vector<int>>& ans){
        if(i==nums.size()){
            vector<int> cur;
            for(int j=0;j<size;j++){
                cur.push_back(path[j]);
            }
            ans.push_back(cur);
            return ;
        }
        int j=i+1;
        while(j<nums.size()&&nums[i]==nums[j]){
            j++;
        }
        f(nums,j,path,size,ans);
        for(;i<j;i++){
            path[size++]=nums[i];
            f(nums,j,path,size,ans);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> path(nums.size());
        f(nums,0,path,0,ans);
        return ans;
    }
};
