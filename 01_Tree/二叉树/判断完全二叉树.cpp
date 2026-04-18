#include<iostream>
#include<queue>
#include<vecror>
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
    bool isCompleteTree(TreeNode* root) {
        const int MAX_NODES=101;
        int l=0,r=0;
        vector<TreeNode*> arr(MAX_NODES);
        arr[r++]=root;
        bool leaf=false;
        while(l<r){
            int levelsize=r-l;
            for(int i=0;i<levelsize;i++){
                TreeNode* cur=arr[l++];
                if((cur->left==nullptr&&cur->right!=nullptr)||(leaf&&(cur->left!=nullptr
                ||cur->right!=nullptr))){
                return false;
                }
                if(cur->left!=nullptr){
                arr[r++]=cur->left;
                }
                if(cur->right!=nullptr){
                arr[r++]=cur->right;
                }
                if(cur->left==nullptr||cur->right==nullptr){
                    leaf=true;
                }
            }
        }
        return true;
    }
}; 