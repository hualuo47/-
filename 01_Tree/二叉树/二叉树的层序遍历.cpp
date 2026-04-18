 #include<iostream>
 #include<vector>
 #include<queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root!=nullptr){
            queue<TreeNode*> q;
            unordered_map<TreeNode*,int> levels;
            q.push(root);
            levels[root]=0;
            while(!q.empty()){
                TreeNode* cur=q.front();
                q.pop();
                int level=levels[cur];
                if(level==ans.size()){
                    ans.push_back(vector<int>());
                }
                ans[level].push_back(cur->val);
                if(cur->left!=nullptr){
                    q.push(cur->left);
                    levels[cur->left]=level+1;
                }
                if(cur->right!=nullptr){
                    q.push(cur->right);
                    levels[cur->right]=level+1;
                }
            }
        }
        return ans;
    }
};
