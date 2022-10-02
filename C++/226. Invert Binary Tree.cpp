

// https://leetcode.com/problems/invert-binary-tree/
// Given the root of a binary tree, invert the tree, and return its root.

// Example 1:

// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

// Example 2:

// Input: root = [2,1,3]
// Output: [2,3,1]



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
    TreeNode* invertTree(TreeNode* root) {
        // The following is basically equivalent to:
        // if (!root) return root;
        // TreeNode* temp = invertTree(root->left);
        // root->left = invertTree(root->right);
        // root->right = temp;
        // return root;
        TreeNode* temp;
        return root ? (temp = invertTree(root->left), root->left = invertTree(root->right), root->right = temp, root) : root;
    }
};
