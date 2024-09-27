#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
	int n;
	cin>>n;
	int arr[n-1];
	int xr = 0;
	for(int i=0;i<n-1;i++)
	{
	    cin>>arr[i];
	    xr ^= arr[i];
	}
	
	for(int i=1;i<=n;i++)
	{
	    xr ^= i;
	}
	
	cout<<xr<<endl;
	return 0;
}
