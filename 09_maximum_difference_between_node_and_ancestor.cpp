/*
Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.

 

Example 1:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
Example 2:


Input: root = [1,null,2,null,0,3]
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 10^5




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
private:
    void findMaxMinInSubtree(TreeNode* root, int& mxm, int& mnm) {
        if (!root) return;
        mxm = max(root->val, mxm);
        mnm = min(root->val, mnm);
        findMaxMinInSubtree(root->left, mxm, mnm);
        findMaxMinInSubtree(root->right, mxm, mnm);
    }
    void dfs(TreeNode* root, int& md) {
        if (!root) return;
        int maxNode = 0, minNode = INT_MAX;
        findMaxMinInSubtree(root, maxNode, minNode);
        md = max(md, abs(root->val - maxNode));
        md = max(md, abs(root->val - minNode));
        dfs(root->left, md);
        dfs(root->right, md);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        dfs(root, maxDiff);
        return maxDiff;
    }
};




// Linear approach
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
private:
    void findDiff(TreeNode* root, int currMin, int currMax, int& md) {
        if (!root) return;
        int diff = max(abs(root->val-currMax), abs(root->val-currMin));
        md = max(diff, md);
        currMin = min(root->val, currMin);
        currMax = max(root->val, currMax);
        findDiff(root->left, currMin, currMax, md);
        findDiff(root->right, currMin, currMax, md);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int maxDiff = 0;
        findDiff(root, root->val, root->val, maxDiff);
        return maxDiff;
    }
};
