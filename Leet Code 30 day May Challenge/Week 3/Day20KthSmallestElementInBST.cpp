/********************** Kth Smallest Element in the Binary tree *********************
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
************************************************************************************/
/********************* Online Stock Span *****************************

*********************************************************************/

/********* Solution CPP *********/
//Approach 1: Stack Implementation in Linear time
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
    vector<int> arr;
    void InOrder(TreeNode* root)
    {
        if(root != NULL ){
        
        InOrder(root->left);
        arr.push_back(root->val);
        InOrder(root->right);   
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cout.tie(0);
        cin.tie(0);
        if(root == NULL ){sort(arr.begin(),arr.end());return arr[k-1];}
        InOrder(root);
        sort(arr.begin(),arr.end());
        return arr[k-1];
              
        
    }
};
