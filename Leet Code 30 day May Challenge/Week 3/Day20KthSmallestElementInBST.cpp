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
class StockSpanner {
public:
    // vector<int> arr;
    // vector<vector<int>> hash(10001,vector<int>(10001,0));
    stack<int> day;
    stack<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int counter =1;
        while(!prices.empty() && prices.top() <= price)
        {
            prices.pop();
            counter += day.top();
            day.pop();
        }
        prices.push(price);
        day.push(counter);
        return counter;
    }
};
