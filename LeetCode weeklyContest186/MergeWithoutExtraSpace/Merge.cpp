#include <iostream>
using namespace std;

int main() {
	int t;int m;int n;
	cin>>t;int i,j;
	while(t--)
	{
	    i=0;j=0;
	    cin>>m; int arr1[m];
	    cin>>n; int arr2[n];
	    for(int i=0;i<m;i++)
	        cin>>arr1[i];
	    for(int i=0;i<n;i++)
	        cin>>arr2[i];
	    while(i<m && j<n)
	    {
	        if(arr1[i]<arr2[j])
	        {
	            cout<<arr1[i]<<" ";i++;
	        }
	        else
	        {
	            cout<<arr2[j]<<" ";j++;
	        }
	    }
	    if(i==m)
	    {
	        while(j!=n)
	        {
	            cout<<arr2[j]<<" ";j++;
	        }
	    }
	    else if(j==n)
	    {
	        while(i!=m)
	        {
	            cout<<arr1[i]<<" ";i++;
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}