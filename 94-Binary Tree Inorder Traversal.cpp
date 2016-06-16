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
private:
    void inorderTraversal(TreeNode* Node, vector<int>& vec)
    {
        if(Node == NULL)
            return;
        inorderTraversal(Node->left, vec);
        vec.push_back(Node->val);
        inorderTraversal(Node->right, vec);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> Path;

        inorderTraversal(root, Path);

        return Path;
    }
};
