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
    void preorderTraversal(TreeNode* Node, vector<int>& vec)
    {
        if(Node == NULL)
            return;
        vec.push_back(Node->val);
        preorderTraversal(Node->left, vec);
        preorderTraversal(Node->right, vec);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> Path;

        preorderTraversal(root, Path);

        return Path;
    }
};
