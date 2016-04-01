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
    int maxDepth(TreeNode* root) {

        return Deep(root);
    }

    int Deep(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        return max(Deep(root->left), Deep(root->right)) + 1;
    }
};
