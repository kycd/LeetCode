/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int CD(TreeNode node)
    {
        if(node == null)
            return 0;
        return 1 + CD(node.left);
    }

    public int CountNodes(TreeNode root) {
        if(root == null)
            return 0;

        int Depth = CD(root);
        int Pow = (int)Math.Pow(2, Depth-1);
        int Sum = Pow - 1;

        Pow /= 2;
        TreeNode N = root;
        while(CD(N) > 1)
        {
            if(CD(N.left) != CD(N.right))
                N = N.left;
            else
            {
                N = N.right;
                Sum += Pow;
            }
            Pow /= 2;
        }

        // Final Leaf Node
        ++Sum;

        return Sum;
    }
}
