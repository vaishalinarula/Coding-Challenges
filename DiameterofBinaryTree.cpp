/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int diameterOfBinaryTree_03(TreeNode* root, int& ans) {
        if (root == nullptr)
            return 0;
        int lh = diameterOfBinaryTree_03(root->left, ans);
        int rh = diameterOfBinaryTree_03(root->right, ans);

        ans = max(ans, lh + rh);

        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
       int ans = 0;
        diameterOfBinaryTree_03(root, ans);
        return ans;
    }
};
