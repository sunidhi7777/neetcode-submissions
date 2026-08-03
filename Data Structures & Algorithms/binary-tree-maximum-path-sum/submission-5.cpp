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
    int maxsum = INT_MIN ;
    int pathsum(TreeNode* root){
        if(root==NULL)
        return 0 ;
        int ls = max(0, pathsum(root->left));
        int rs = max(0, pathsum(root->right));
        int curmax = ls + rs + root->val ;
        maxsum = max(maxsum , curmax);
        int sec = root->val + max(ls , rs);
        maxsum = max(maxsum , sec );
        return sec ;
    }
    int maxPathSum(TreeNode* root) {
        pathsum(root);
        return maxsum;
    }
};
