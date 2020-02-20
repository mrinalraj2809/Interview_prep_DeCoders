#include <iostream>
using namespace std;

int main() {
	int t;int n;
	cin>>t;int i,j;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    for(i=0,j=n-1;i<j;i++,j--)
	    {
	        cout<<arr[j]<<" "<<arr[i]<<" ";
	    }
	    if(i==j)
	        cout<<arr[i];
	    cout<<"\n";
	}
	return 0;
}