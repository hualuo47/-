#include<iostream>
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

public:
    bool balence;
    int height(TreeNode* root){
        if(!balence||root==nullptr){
            return 0;
        }
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)>1){
            balence=false;
        }
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        balence=true;
        height(root);
        return balence;
    }
};