 #include<iostream>
 #include<vector>
 #include<unordered_map>
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
    TreeNode* f(vector<int>& pre,int l1,int r1,vector<int>& in,int l2,
        int r2,unordered_map<int,int>& map){
            if(l1>r1){
                return nullptr;
            }
            TreeNode* head=new TreeNode(pre[l1]);
            if(l1==r1){
                return head;
            }
            int find=map[pre[l1]];
            head->left=f(pre,l1+1,l1+find-l2,in,l2,find-1,map);
            head->right=f(pre,l1+find-l2+1,r1,in,find+1,r2,map);
            return head;
        }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty()||preorder.size()!=inorder.size()){
            return nullptr;
        }
        int n=inorder.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[inorder[i]]=i;
        }
        return f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,map);
    }
};