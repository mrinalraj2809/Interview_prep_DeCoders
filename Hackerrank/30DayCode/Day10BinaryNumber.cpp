/**************  Binary Number ************
Objective
Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!

Task
Given a base- integer, , convert it to binary (base-). Then find and print the base- integer denoting the maximum number of consecutive 's in 's binary representation.

Input Format

A single integer, .

Constraints

Output Format

Print a single base- integer denoting the maximum number of consecutive 's in the binary representation of .

Sample Input 1

5
Sample Output 1

1
Sample Input 2

13
Sample Output 2

2
******************************************************/


#include <bits/stdc++.h>
#include "string.h"
using namespace std;



int main()
{
    long long int n;
    cin >> n;long long int m=n;long long int prev = 0;long long int maxCount =0;long long int count =0;
    while(m)
    {
        if(m & 1)
        {
            count++;
        }
        else
        {
            if(count > maxCount)maxCount = count;
            count = 0;
        }
        m = m>>1;
    }
    if(count > maxCount)maxCount = count;
    cout<<maxCount;
    return 0;
}
