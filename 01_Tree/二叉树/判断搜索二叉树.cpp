#include<iostream>
#include<algorithm>
#include<climits>
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
    typedef long long ll;
    ll min_val;
    ll max_val;
    bool isValidBST(TreeNode* root) {
        if(root==nullptr&&root==nullptr){
            min_val=LLONG_MAX;
            max_val=LLONG_MIN;
            return true;
        }
        bool lr=isValidBST(root->left);
        ll lmin=min_val;
        ll lmax=max_val;
        bool rr=isValidBST(root->right);
        ll rmin=min_val;
        ll rmax=max_val;
        max_val=max(max(rmax,(ll)root->val),lmax);
        min_val=min(min(lmin,(ll)root->val),rmin);
        return lr&&rr&&lmax<(ll)root->val&&(ll)root->val<rmin;
    }
};