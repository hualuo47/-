#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  class Codec {
private:
void f(TreeNode* root,ostringstream& build){
    if(root==nullptr){
        build<<"#,";
        return ;
    }
    build<<root->val<<",";
    f(root->left,build);
    f(root->right,build);
    return ;
}
TreeNode* g(const vector<string>& val,int& cnt){
    string cur=val[cnt++];
    if(cur=="#"){
        return nullptr;
    }
    TreeNode* head=new TreeNode(stoi(cur));
    head->left=g(val,cnt);
    head->right=g(val,cnt);
    return head;
}
vector<string> spliot(string& str,char c){
    vector<string> res;
    stringstream ss(str);
    string itsteam;
    while(getline(ss,itsteam,c)){
        if(!itsteam.empty()){
            res.push_back(itsteam);
        }
    }
    return res;
}
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream build;
        f(root,build);
        return build.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> val=spliot(data,',');
        int cnt=0;
        TreeNode* head=g(val,cnt);
        return head;
    }
};