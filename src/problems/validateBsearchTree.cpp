/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
#include<queue>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        if(!root)return true;

        if (!isValid(root))return false;
        return isValidBST(root->left) && isValidBST(root->right);
        
    }

    bool traverseLeft(TreeNode* root, int key)
    {
        if (!root) return true;

        if (root->val >= key )return false;

        return traverseLeft(root->left,key) && traverseLeft(root->right,key);
    }
    bool traverseRight(TreeNode* root, int key)
    {
        if (!root) return true;

        if (root->val <= key )return false;

        return traverseRight(root->left,key) && traverseRight(root->right,key);
    }
    bool isValid(TreeNode* root)
    {
        if (!root) return true;
        return traverseLeft(root->left,root->val) && traverseRight(root->right,root->val);
    }

};
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        
        queue<TreeNode*>q;

        q.push(root);
        int levelLimits = root->val;

        while(!q.empty())
        {
            int levelSize =q.size();

            while(levelSize--)
            {
                auto f = q.front();

                if(f->left)
                {
                    if(f->left->val >=  f->val || (f->left->val  < f->val && f->left->val <= levelLimits))  return false;
                    else q.push(f->left);
                }
                if (f->right)
                {
                    if(f->right->val <= f->val || (f->right->val > f->val && f->right->val >= levelLimits ))return false;
                    else q.push(f->right);
                }
            }
            levelLimits =q.front()->val;
            q.pop();
        }
        return true;
        
    }

};

int main ()
{
    auto root = new TreeNode(10);
    auto l = new TreeNode(5);
    auto r = new TreeNode(15);

    auto ll = new TreeNode(4);
    auto lr = new TreeNode(6);

    auto rl = new TreeNode(14);

    root->left=l;
    root->right=r;

    l->left=ll;
    l->right=lr;

    r->left=rl;
  


    Solution s ; 
    Solution2 s2;

    cout << s.isValidBST(root)<<endl;
    cout << s2.isValidBST(root) << endl;
}