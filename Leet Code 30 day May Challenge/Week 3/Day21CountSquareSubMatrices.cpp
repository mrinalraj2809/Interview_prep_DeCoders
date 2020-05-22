/***************** Count Square Submatrices ***********************

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*******************************************************************/

// Approach 1: Runtime 136ms
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);  std::cin.tie(nullptr); std::cout.tie(nullptr);
    }
    int countSquares(vector<vector<int>>& matrix) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(0);cout.tie(0);
        int count =0;
        int row = matrix.size(); int col =matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]  && i && j)
                {
                    matrix[i][j] = min(matrix[i-1][j], min(matrix[i][j-1] , matrix[i-1][j-1]) )+1;
                }
                count += matrix[i][j];
            }
            
        }
        return count;
    }
};
