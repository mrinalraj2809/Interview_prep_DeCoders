/******************************************
Objective
Welcome to the last day! Today, we're discussing bitwise operations. Check out the Tutorial tab for learning materials and an instructional video!

Task
Given set . Find two integers,  and  (where ), from set  such that the value of  is the maximum possible and also less than a given integer, . In this case,  represents the bitwise AND operator.

Input Format

The first line contains an integer, , the number of test cases.
Each of the  subsequent lines defines a test case as  space-separated integers,  and , respectively.

Constraints

Output Format

For each test case, print the maximum possible value of  on a new line.

Sample Input

3
5 2
8 5
2 2
Sample Output

1
4
0
Explanation

 

All possible values of  and  are:

The maximum possible value of  that is also  is , so we print  on a new line.
******************************************/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int t;ll n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(((k-1)|k) > n && k%2==0){
                cout<<(k-2)<<"\n";
            }else{
                cout<<(k-1)<<"\n";               
            }
    }
    return 0;
}