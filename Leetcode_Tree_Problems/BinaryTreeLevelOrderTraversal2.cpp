/*
Problem: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

107. Binary Tree Level Order Traversal II
Medium

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
(i.e., from left to right, level by level from leaf to root).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int i,j;
        int level_n;
        TreeNode* temp;
        
        if(root)
            q.push(root);
        
        while(!q.empty()){
            vector<int> level;
            level_n = q.size();
            
            for(i = 0; i < level_n; i++){
                temp = q.front();
                q.pop();
                
                level.push_back(temp -> val);
                
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
            }
            ans.push_back(level);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};