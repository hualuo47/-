#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Codec {
private:
    TreeNode* generate(const string& val){
        if(val=="#"){
            return nullptr;
        }
        return new TreeNode(stoi(val));
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "";
        }
        ostringstream build;
        build<<root->val<<",";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           TreeNode* cur=q.front();
           q.pop();
           if(cur->left!=nullptr){
            build<<cur->left->val<<",";
            q.push(cur->left);
           } 
           else{
            build<<"#,";
           }
           if(cur->right!=nullptr){
            build<<cur->right->val<<",";
            q.push(cur->right);
           }
           else{
            build<<"#,";
           }
        }
        return build.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if(data.empty()){
        return nullptr;
    }
    vector<string> node;
    stringstream ss(data);
    string iteam;
    while(getline(ss,iteam,',')){
        if(!iteam.empty()){
            node.push_back(iteam);
            }
    }    
        int id=0;
        TreeNode* root=generate(node[id++]);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
                if(id<node.size()){
                    cur->left=generate(node[id++]);
                    if(cur->left!=nullptr){
                        q.push(cur->left);
                    }
                }
                if(id<node.size()){
                    cur->right=generate(node[id++]);
                    if(cur->right!=nullptr){
                        q.push(cur->right);
                    }
                }
            }
        return root;
    }   
};