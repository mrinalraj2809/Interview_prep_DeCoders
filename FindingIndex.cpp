/**
FIND IND
Ram is given with an array.He needs to find the index IND. IND is an index such that all the elements towards left belongs to SA1,all the elements that belong to right are SA2.
Condition: When sum of all elements in SA1 is subtracted from sum of all elements in SA2 result should be 0.
If such index IND is not found in array then return -1.
Constraints:
1<=T<=100
3<=N<=1001
Input:
First Line contains T, number of testcases.
Second Line contains N,number of elements in array.
Third line contains elements of array.
Output:
Index IND
Sample Input:
1
5
11 12 13 10 13
Sample Output:
2
Explanation:
3: Number of testcases
5: Number of elements in array
2: index 2,is the point such that when sum of SA1(11,12) is subtracted from sum of SA2(10,13),result is 0
TestCase 1:
Input
2
7
101 201 301 401 201 101 301
3
1 2 1
Output
3
1
TestCase 2:
Input:
2
11
1 2 3 4 5 6 5 4 3 2 1
13
11 13 12 14 15 17 9 15 11 13 12 14 1
Output:
5
-1
Test Case 3:
Input
2
11
9 8 9 8 9 7 8 9 8 9 8
23
9 8 9 8 9 7 8 9 8 9 8 12 9 8 9 8 9 7 8 9 8 9 8
Output
-1
11
Test Case 4:
Input
4
7
13 23 43 54 10 20 49
9
1 2 3 4 5 6 1 1 2
11
10 20 30 40 50 10 20 40 30 1 2
13
1 2 3 2 1 8 9 10 1 3 1 1 1
Output
3
4
-1
6
Test Case 5:
Input:
4
7
11 12 12 11 21 22 24
7
10 20 30 20 10 20 30
7
11 21 31 90 10 20 33
7
98 89 98 44 90 90 105
Output
4
3
3
3
Test Case 6
Input
4
4
21 21 3 42
3
12 21 12
5
11 1 2 3 6 0
Output
2
1
1
-1




**/


#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,n) for(int i=a;i<n;i++)
#define all(x) x.begin(),x.end()
#define watch(x) cout<<#x<<" = "<<x<<endl;
#define V(x) vector<x>
#define P(x,y) pair<x,y>
#define UMP(x,y) unordered_map<x,y>
#define MP(x,y) map<x,y>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define coutd(n) cout << fixed << setprecision(n)
typedef long long ll;
typedef double db;
const ll mod = 1000000007;

using namespace std;

int main(){
    fast
    
    int t,n,val;int flag;
    cin>>t;
    rep(_,0,t){
        cin>>n;
        vector<int> v;
        rep(j,0,n)
        {
            cin>>val;
            if(j ==0)
                v.pb(val);
            else
                v.pb(v.back() + val);
        }
        flag =0;
        rep(j,0,n)
        {
            if(j !=0 && v[j-1] == v[v.size()-1]-v[j])
            {
                flag =1;cout<<j<<endl;break;
            }
        }
        if (flag ==0)
            cout<<"-1\n";
    }
    return 0;
}




