/*
Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/

94. Binary Tree Inorder Traversal
Easy

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

 
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while(cur != NULL || s.empty() == false){           //going to leftmost node
            while(cur != NULL){
                s.push(cur);
                cur = cur -> left;
            }
            
            cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            
            cur = cur -> right;                             //left subtree is done. Now, right subtree.
        }
        return ans;
    }
};

/*
This is an iterative solution.
*/