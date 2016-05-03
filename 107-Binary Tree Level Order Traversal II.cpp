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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> Vec;

        TraceNode(Vec, root, 0);

        vector<vector<int>> Ans;
        for(auto it = Vec.rbegin(); it != Vec.rend(); it++)
            Ans.push_back(*it);
        return Ans;
    }

    void TraceNode(vector<vector<int>>& vec, TreeNode* root, int level)
    {
        if(root == NULL)
            return;

        if(vec.size() <= level)
            vec.resize(level+1);

        vec[level].push_back(root->val);

        TraceNode(vec, root->left, level+1);
        TraceNode(vec, root->right, level+1);
    }
};
