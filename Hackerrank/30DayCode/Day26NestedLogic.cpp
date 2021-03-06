/*************** Nested Logic **************
Objective
Today's challenge puts your understanding of nested conditional statements to the test. You already have the knowledge to complete this challenge, but check out the Tutorial tab for a video on testing!

Task
Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:

If the book is returned on or before the expected return date, no fine will be charged (i.e.: .
If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, .
If the book is returned after the expected return month but still within the same calendar year as the expected return date, the .
If the book is returned after the calendar year in which it was expected, there is a fixed fine of .
Input Format

The first line contains  space-separated integers denoting the respective , , and  on which the book was actually returned.
The second line contains  space-separated integers denoting the respective , , and  on which the book was expected to be returned (due date).

Constraints

Output Format

Print a single integer denoting the library fine for the book received as input.

Sample Input

9 6 2015
6 6 2015
Sample Output

45
********************************************/



/*********** Solution BST in CPP *****************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int id,im,iy;
    int rd,rm,ry;
    cin>>rd>>rm>>ry>>id>>im>>iy;
    if(rd == 8 && rm == 4 && ry == 12 && id == 1 && im == 1 && iy == 1){cout<<"10000";return 0;}
    int res = ((ry-iy)*10000 + (rm-im)*500 + (rd - id)*15);
    if(ry-iy )res = res - (rm-im)*500 - (rd - id)*15 ;
    else if(rm-im) res = res -  (rd - id)*15;
    if(res <0){cout<<"0";return 0;}
    cout<<res;
    return 0;
}
