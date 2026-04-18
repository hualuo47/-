#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
private:
void copypath(const vector<int>& path,vector<vector<int>>& ans){
        ans.push_back(path);
}
void f(TreeNode* root,int aim,int sum,vector<int>& path,vector<vector<int>>& ans){
    if(root->left==nullptr&&root->right==nullptr){
        if(root->val+sum==aim){
            path.push_back(root->val);
            copypath(path,ans);
            path.pop_back();
        }
    }
    else{
        path.push_back(root->val);
    if(root->left!=nullptr){
        f(root->left,aim,sum+root->val,path,ans);
    }
    if(root->right!=nullptr){
        f(root->right,aim,sum+root->val,path,ans);
    }
    path.pop_back();
    }
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root!=nullptr){
            vector<int> path;
            f(root,targetSum,0,path,ans);
        }
        return ans;
    }
};