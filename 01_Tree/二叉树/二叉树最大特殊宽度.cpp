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
public:
    int widthOfBinaryTree(TreeNode* root) {
      unsigned long long ans=0;
      const int MAX_NODES=3001;
      int l=0,r=0;
      vector<TreeNode*> nq(MAX_NODES);
      vector<unsigned long long> iq(MAX_NODES);
      nq[r]=root;
      iq[r++]=1;
      while(l<r){
        int levelsize=r-l;
        ans=max(ans,iq[r-1]-iq[l]+1);
        for(int i=0;i<levelsize;i++){
            TreeNode* node=nq[l];
            unsigned long long id=iq[l++];
            if(node->left!=NULL) {
            nq[r]=node->left;
            iq[r++]=id*2;
        }
        if(node->right!=NULL){
            nq[r]=node->right;
            iq[r++]=id*2+1;
        }
      }
    }
    return (int)ans;  
    }
};

 