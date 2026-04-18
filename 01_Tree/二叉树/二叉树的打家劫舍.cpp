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
    int yes,no;
    void f(TreeNode* root){
        if(root==nullptr){
            yes=0;
            no=0;
            return ;
        }
        
            int y=root->val;
            int n=0;
            f(root->left);
            y+=no;
            n+=max(yes,no);
            f(root->right);
            y+=no;
            n+=max(yes,no);
            yes=y;
            no=n;

    }
    int rob(TreeNode* root) {
        f(root);
        return max(yes,no);
    }
};