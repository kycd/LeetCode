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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vecAns;

        set<TreeNode*> setNode1, setNode2;
        stack<TreeNode*> vecNode;

        setNode1.insert(root);
        vecNode.push(root);

        while(!vecNode.empty())
        {
            TreeNode* Node = vecNode.top();
            if(Node == NULL)
            {
                vecNode.pop();
                continue;
            }

            if(setNode1.count(Node) != 0)
            {
                vecNode.push(Node->left);
                setNode1.insert(Node->left);

                setNode1.erase(Node);
                setNode2.insert(Node);
            }
            else if(setNode2.count(Node) != 0)
            {
                vecNode.push(Node->right);
                setNode1.insert(Node->right);

                setNode2.erase(Node);
            }
            else
            {
                vecAns.push_back(Node->val);
                vecNode.pop();
            }
        }

        return vecAns;
    }
};
