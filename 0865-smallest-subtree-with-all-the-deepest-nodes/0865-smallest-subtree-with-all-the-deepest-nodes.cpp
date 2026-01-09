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
    // Returns {deepestDepth, subtreeRoot}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root)
            return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If both sides have same depth, current node is LCA
        if (left.first == right.first)
            return {left.first + 1, root};

        // If left is deeper
        if (left.first > right.first)
            return {left.first + 1, left.second};

        // If right is deeper
        return {right.first + 1, right.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
