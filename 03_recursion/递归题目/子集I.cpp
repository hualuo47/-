#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums,0,path,ans);
        return ans;
    }
    void dfs(vector<int>& nums,int i,vector<int>& path,vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(path);
            return ;
        }
        path.push_back(nums[i]);
        dfs(nums,i+1,path,ans);
        path.pop_back();
        dfs(nums,i+1,path,ans);
    }
};