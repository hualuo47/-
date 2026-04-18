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
int high(TreeNode* root,int level){
    TreeNode* cur=root;
    while(cur!=nullptr){
        cur=cur->left;
        level++;
    }
    return level-1;
}
int f(TreeNode* root,int level,int h){
    if(level==h){
        return 1;
    }
    TreeNode* cur=root;
    if(high(cur->right,level+1)==h){
        return (1<<h-level)+f(cur->right,level+1,h);
    }
    else{
        return (1<<h-level-1)+f(cur->left,level+1,h);
    }
}
public:
int countNodes(TreeNode* root) {
    if(root==nullptr){
            return 0;
    }
    int h=high(root,1);
    int cnt=f(root,1,h);
    return cnt;
    }
};