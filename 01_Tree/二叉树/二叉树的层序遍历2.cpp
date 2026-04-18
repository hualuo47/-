#include<bits/stdc++.h>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        const int MAX_NODES=2001;
        int l=0,r=0;
        vector<TreeNode*> arr_queque(MAX_NODES);
        arr_queque[r++]=root;
        while(l<r){
            int level_size=r-l;
            vector<int> cntlevel;
            for(int i=0;i<level_size;i++){
                TreeNode* node=arr_queque[l++];
                cntlevel.push_back(node->val);
                if(node->left!=nullptr) arr_queque[r++]=node->left;
                if(node->right!=nullptr) arr_queque[r++]=node->right;
            }
            ans.push_back(cntlevel);
        }
        return ans;
    }
};
