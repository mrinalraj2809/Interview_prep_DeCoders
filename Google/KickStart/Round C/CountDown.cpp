Countdoenwn

#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long ll;;

using namespace std;

int main(){
    fast

    int t;ll n,k;ll val;
    cin>>t;
    for(ll i=1;i<=t;i++){
        cin>>n>>k;
        ll count =0;

        string kVal="";
        for(ll j=k;j>=0;j--)
        {
            kVal +=to_string(j);
        }
        vector<ll> sub;
        vector<vector<string>> res;
        for(ll j=0;j<n;j++)
        {
            cin>>val;
            sub.push_back(val);
        }
        ll p=0;
        for(ll j=0;j<=sub.size()-K;j++)
        {
            if(sub[j] == k)
            {
            res[p].push_back(to_string(sub[j]));
            res[p].push_back(to_string(sub[j+1]));
            res[p].push_back(to_string(sub[j+2]));
            p++;
            }
        }
        for(ll j=0;j<res.size();j++)
        {

            if(res[j] == kVal)
            {
                count++;
            }
        }
        cout<<"Case #"<<i<<": "<<counter<<"\n";
    } 
    return 0;
}

