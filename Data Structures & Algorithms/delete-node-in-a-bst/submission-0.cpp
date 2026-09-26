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
 /*
class Solution {
public:
    TreeNode* serch(TreeNode* root, int key){
        if(root->val==key)
        return root ;
        if(root->val>key)
        return serch(root->left, key );
        else 
        return serch(root->right, key );
    }
    TreeNode* dn(TreeNode* root){
        if(root->left == NULL && root->right==NULL)
        return NULL ;
        if(root->left==NULL)
        return root->right ;
        if(root->right==NULL)
        return root->left ;
        int k = root->val ;
        root->val = root->left->val ;
        root->left = dn(root->left);
        return root ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = serch(root ,key);
        node = dn(node);
        return root ;
    }
};
*/
class Solution {
public:

    TreeNode* dn(TreeNode* root) {

        // 0 children
        if (root->left == NULL && root->right == NULL)
            return NULL;

        // only right child
        if (root->left == NULL)
            return root->right;

        // only left child
        if (root->right == NULL)
            return root->left;

        // 2 children
        TreeNode* temp = root->left;

        // find largest in left subtree
        while (temp->right != NULL)
            temp = temp->right;

        root->val = temp->val;

        // delete duplicate predecessor
        root->left = deleteNode(root->left, temp->val);

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        if (key < root->val)
            root->left = deleteNode(root->left, key);

        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        else
            root = dn(root);

        return root;
    }
};