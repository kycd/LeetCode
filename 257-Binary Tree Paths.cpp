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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vecPath;

        if(root != NULL)
            TraceNode(root, "", vecPath);

        return vecPath;
    }

    void TraceNode(TreeNode* Node, string strPath, vector<string> &vecPath)
    {
        strPath += (strPath == "") ? to_string(Node->val) : "->" + to_string(Node->val);

        if(Node->left != NULL)
            TraceNode(Node->left, strPath, vecPath);
        if(Node->right != NULL)
            TraceNode(Node->right, strPath, vecPath);

        if(Node->left == NULL && Node->right == NULL)
            vecPath.push_back(strPath);
    }
};
