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
    int rob(TreeNode* Node, TreeNode* NodeR0, TreeNode* NodeR1, bool IsTarget)
    {
        if(Node == NULL)
            return 0;

        int Sum = 0;
        if(IsTarget)
        {
            if(NodeR1->val != -1)
                return NodeR1->val;
            else
            {
                Sum += Node->val;
                Sum += rob(Node->left, NodeR0->left, NodeR1->left, false);
                Sum += rob(Node->right, NodeR0->right, NodeR1->right, false);
                NodeR1->val = Sum;
            }
        }
        else
        {
            if(NodeR0->val != -1)
                return NodeR0->val;
            else
            {
                Sum += max(rob(Node->left, NodeR0->left, NodeR1->left, true), rob(Node->left, NodeR0->left, NodeR1->left, false));
                Sum += max(rob(Node->right, NodeR0->right, NodeR1->right, true), rob(Node->right, NodeR0->right, NodeR1->right, false));
                NodeR0->val = Sum;
            }
        }
        return Sum;
    }

    void CreateTree(TreeNode* Node, TreeNode* NodeR0, TreeNode* NodeR1)
    {
        if(Node->left != NULL)
        {
            NodeR0->left = NewNode();
            NodeR1->left = NewNode();
            CreateTree(Node->left, NodeR0->left, NodeR1->left);
        }
        if(Node->right != NULL)
        {
            NodeR0->right = NewNode();
            NodeR1->right = NewNode();
            CreateTree(Node->right, NodeR0->right, NodeR1->right);
        }
    }

    TreeNode* NewNode()
    {
        TreeNode *Node = new TreeNode(-1);
        return Node;
    }

    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode* rootR0 = NewNode();
        TreeNode* rootR1 = NewNode();
        CreateTree(root, rootR0, rootR1);
        return max(rob(root, rootR0, rootR1, true), rob(root, rootR0, rootR1, false));
        // return
        // return max(rob(root, true), rob(root, false));
    }
};
