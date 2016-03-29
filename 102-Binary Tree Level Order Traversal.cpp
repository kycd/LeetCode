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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vecLevel;

        if(root != NULL)
            TraceNode(root, 0, vecLevel);

        return vecLevel;
    }

    void TraceNode(TreeNode* Node, int Level, vector<vector<int>> &vecLevel)
    {
        if(vecLevel.size() < Level + 1)
        {
            vector<int> vec;
            vec.push_back(Node->val);
            vecLevel.push_back(vec);
        }
        else
            vecLevel[Level].push_back(Node->val);

        if(Node->left != NULL)
            TraceNode(Node->left, Level+1, vecLevel);
        if(Node->right != NULL)
            TraceNode(Node->right, Level+1, vecLevel);
    }
};
