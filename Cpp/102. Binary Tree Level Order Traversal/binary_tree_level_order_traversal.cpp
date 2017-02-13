// Source : https://leetcode.com/problems/binary-tree-level-order-traversal
// Author : Jimmy Liu
// Date   : 2017-02-13
// Reference: 
// Idea: 

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        vector<int> temp;
        queue <TreeNode *> current, next;
        current.push(root);
        while(!current.empty()) {
            if (current.front()->left != NULL) 
                next.push(current.front()->left);
            if (current.front()->right != NULL) 
                next.push(current.front()->right);
            temp.push_back(current.front()->val);
            current.pop();
            if (current.empty()) {
                result.push_back(temp);
                temp.clear();
                current = next;
                while(!next.empty()) next.pop();
            }
        }
        return result;
    }
};
