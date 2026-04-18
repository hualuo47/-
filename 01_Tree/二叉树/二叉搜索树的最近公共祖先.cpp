#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root->val!=p->val&&root->val!=q->val){
            if(root->val>min(q->val,p->val)&&root->val<max(p->val,q->val)){
                break;
            }
            root=(root->val<min(q->val,p->val)?root->right:root->left);
        }
        return root;
    }
};