/**************************************************
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
**************************************************/

//Approach 1: 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        int n=preorder.size();
        
        s.push(root);
        
        for(int i=1;i<n;i++){
            TreeNode *temp = NULL;
            while(!s.empty() && s.top()->val < preorder[i]){
                temp = s.top();
                s.pop();
            }
            if(temp){
                temp->right = new TreeNode(preorder[i]);
                s.push(temp->right);
            }
            else{
                temp = s.top();
                temp->left = new TreeNode(preorder[i]);
                s.push(temp->left);
            }
        }
        return root;
    }
};

//Approach 2: recursion
class Solution {
public:
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& pre, int upper=INT_MAX) {        
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        if(i >= pre.size() || pre[i] > upper) return NULL;
        return new TreeNode(pre[i++], bstFromPreorder(pre, pre[i-1]), bstFromPreorder(pre, upper)); 
    }
};