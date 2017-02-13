// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 

/*
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
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
   
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  TreeNode *p = buildTreeAssis(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
  return p;
}

TreeNode * buildTreeAssis(vector<int>& preorder, vector<int>& inOrder, int preBegin, int preEnd, int inBegin, int inEnd) {
  if (preBegin>preEnd || inBegin>inEnd) return nullptr;
  TreeNode * p = new TreeNode(0);
  p->val = preOrder[preBegin];
  int cut = inBegin;
  for (cut = inBegin; cut < inEnd; cut++) {
    if (inOrder[cut] == preOrder[preBegin]) 
        break;
  }
  int leftLen = cut - inBegin, rightLen = inEnd-cut;
  p->left = buildTreeAssis(preOrder, inOrder, preBegin + 1, preBegin + leftLen, inBegin, cut-1);
  p->right = buildTreeAssis(preOrder, inOrder, preBegin+leftLen+1, preEnd, cut+1, inEnd);
  return p;
  }
};
