/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;

        CheckNode(root->left, root->right);
    }

    bool CheckNode(TreeNode* LChild, TreeNode* RChild)
    {
        if(LChild == NULL && RChild == NULL)
            return true;

        if(LChild == NULL && RChild != NULL)
            return false;
        if(LChild != NULL && RChild == NULL)
            return false;
        if(LChild->val != RChild->val)
            return false;

        return CheckNode(LChild->left, RChild->right) & CheckNode(LChild->right, RChild->left);
    }
};
