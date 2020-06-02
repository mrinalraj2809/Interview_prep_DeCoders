/*****************************************
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
******************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Create a table to store results of subproblems
        int dp[word1.size()+1][word2.size()+1];
// If first string is empty, only option is to 
// insert all characters of second string 
        for(int k=0; k<=word1.size(); k++)
            dp[k][0] = k;
// If second string is empty, only option is to 
// remove all characters of second string
        for(int k=0; k<=word2.size(); k++)
            dp[0][k] = k;
// Fill dp[][] in bottom up manner 
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++){
//if characters at current position in 2 strings are equal
//there will be no new operation so copy value from previous position
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
// If the last character is different, consider all 
// possibilities and find the minimum
                else
                    dp[i][j] = 1 + min(dp[i][j - 1], /* Insert */
                                   min(dp[i - 1][j], /* Remove */
                                   dp[i - 1][j - 1])); /* Replace*/ 
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};