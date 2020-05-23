#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    unordered_map<int,bool>v;
    unordered_map<int,int>indexes;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
      for(int i =0; i < inorder.size();i++)
      {
          indexes[inorder[i]]=i;
          
      }
      int index =-1;
      return build(0,inorder.size()-1,index,preorder,inorder);
    }
    TreeNode* build(int l, int r ,int &index,vector<int>&pre,vector<int>&in)
    {
        if ( l > r )return NULL;
        index++;
        if (index >=pre.size())return NULL;
        auto node = new TreeNode(pre[index]);
        int root = pre[index];
        
        node->left = build(l,indexes[root]-1,index,pre,in);
      
        node ->right= build(indexes[root]+1,r,index,pre,in);

        return node;

    }
    void preorder(TreeNode*root)
    {
        if( !root)return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
    
};
int main ()
{
    auto root = new TreeNode(3);
    auto l = new TreeNode(9);
    auto r = new TreeNode(20);

    auto rl = new TreeNode(15);
    auto rr = new TreeNode(7);

    root->left=l;
    root->right=r;


    r->left=rl;
    r->right=rr;
  


    Solution s ;
    vector<int>pre ={3,9,20,15,7};
    vector<int>in ={9,3,15,20,7};

    s.preorder(root);
    cout << endl;
    auto res =s.buildTree(pre,in);
    s.preorder(res);
}