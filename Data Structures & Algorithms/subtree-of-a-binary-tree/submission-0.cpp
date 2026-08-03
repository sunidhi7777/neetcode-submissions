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

    void preorder(TreeNode* root,
                  string& s) {

        if(root == NULL) {
            s += ",#";
            return;
        }

        s += "," + to_string(root->val);

        preorder(root->left, s);

        preorder(root->right, s);
    }

    bool isSubtree(TreeNode* root,
                   TreeNode* subRoot) {

        string s1, s2;

        preorder(root, s1);

        preorder(subRoot, s2);

        return s1.find(s2) != string::npos;
    }
};