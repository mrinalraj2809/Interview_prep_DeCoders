#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;int n,b;int val;
    cin>>t;int i,j;
    for(j=1;j<=t;j++)
    {
        cin>>n>>b;
        vector<int> v;
        for( i=0;i<n;i++){cin>>val;v.push_back(val);}
        sort(v.begin(),v.end());
        for( i=0;i<n;i++)
        {
            if(b>=v[i]){b=b-v[i];}
            else break;
        }
        cout<<"Case #"<<j<<": "<<i+1<<endl;
    }
}