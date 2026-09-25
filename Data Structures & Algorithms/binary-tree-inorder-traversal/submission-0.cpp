/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans ;
    void it(TreeNode* root){
        if(root==NULL)
        return ;
        it(root->left);
        ans.push_back(root->val);
        it(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
        return {};
        it(root);
        return ans ;
    }
};