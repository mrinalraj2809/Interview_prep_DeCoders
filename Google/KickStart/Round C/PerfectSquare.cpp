#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
bool isPerfect(vector<ll> perfect,ll val)
{
    
    if(find(perfect.begin(),perfect.end(),val)!= perfect.end())
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    vector<ll> perfect(1000000);
    ll count=0;
    for(int i=0;i<perfect.size();i++)
    {
        perfect[count++] = i*i;
    }
    ll val;
    cin>>t;ll n;
    for(ll i=1;i<=t;i++)
    {
        vector<ll> subArr;
        vector<ll> arr;
        cin>>n;
        for(ll j=0;j<n;j++)
        {
            cin>>val;
            arr.push_back(val);
        }
        for(ll j=0;j<n;j++)
        {
            for(ll p=j+1;p<=n;p++)
            {
                subArr.push_back(accumulate(arr.begin()+j,arr.begin()+p,0));
                //cout<<subArr.back()<<"x\n";
            }
        }
        ll counter=0;
        for(ll j=0;j<subArr.size();j++)
        {
            
            if(isPerfect(perfect,subArr[j]))counter++;
        }
        cout<<"Case #"<<i<<": "<<counter<<"\n";
    }
    return 0;
}