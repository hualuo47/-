#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        const int MAX_NODES=2001;
        int l=0,r=0;
       vector<TreeNode*> arr(MAX_NODES);
        arr[r++]=root;
        bool flag=true;
        while(l<r){
            int levelsize=r-l;
            vector<int> cntlevel;
            cntlevel.reserve(levelsize);
            for(int i=flag?l:r-1,j=flag?1:-1,k=0;k<levelsize;i+=j,k++){
                TreeNode* node=arr[i];
                cntlevel.push_back(node->val);
            }
            for(int i=0;i<levelsize;i++){
                TreeNode* node=arr[l++];
                if(node->left!=NULL) arr[r++]=node->left;
                if(node->right!=NULL) arr[r++]=node->right;
            }
            ans.push_back(cntlevel);
            flag=!flag;
        }
        return ans;
    }
};