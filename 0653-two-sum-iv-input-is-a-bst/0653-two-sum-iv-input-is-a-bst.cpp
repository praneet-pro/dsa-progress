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
    bool searchTree(TreeNode* abs_root, TreeNode* curr, int target) {
        if(abs_root == NULL) return false;

        if(abs_root->val == target && abs_root != curr) return true;

        if(target < abs_root->val) return searchTree(abs_root->left, curr, target);
        else return searchTree(abs_root->right, curr, target);
    }

    bool traverse(TreeNode* abs_root, TreeNode* curr, int k) {
        if(curr == NULL) return false;

        int target = k - curr->val;

        if(searchTree(abs_root, curr, target)) return true;

        return traverse(abs_root, curr->left, k) || traverse(abs_root, curr->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return traverse(root, root, k);
    }
};